ƒ//Alexander Zaytsev
//a.zaytsev@gsi.de
//October 2016

#include "hades.h"
#include "hloop.h"
#include "htime.h"
#include "hcategory.h"
#include "hcategorymanager.h"
#include "hparticlecand.h"
#include "hparticletracksorter.h"
#include "hparticlebooker.h"
#include "hparticletool.h"
#include "hparticledef.h"
#include "hparticleevtinfo.h"
//#include "hparticleevtchara.h"
#include "henergylosscorrpar.h"
#include "hphysicsconstants.h"
#include "hwallhit.h"
#include "walldef.h"

#include "TString.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TFile.h"
#include "TMath.h"
#include "TTree.h"
#include "TRandom2.h"

#include "mhwalldivider.h"

#include <iostream>
#include <vector>

using namespace std;


const Float_t D2R = TMath::DegToRad(); //deg to rad
const Float_t Y_BEAM = 0.740151;  //beam rapidity for 1.23GeV/c nucleon

//  infileList : comma seprated file list "file1.root,file2.root" or "something*.root"
//  outfile    : optional (not used here) , used to store hists in root file
//  nEvents    : number of events to processed. if  nEvents < entries or < 0 the chain will be processed

Int_t makeTree(TString infileList, TString outfile, Int_t nEvents=-1)
{
    Bool_t isSimulation = kFALSE;

    // create loop object and hades
    HLoop loop(kTRUE);

    // list of all files with working sectors
    if(!isSimulation) loop.readSectorFileList("/lustre/nyx/hades/dst/apr12/gen8/sector_selection/FileListHadron.list",kFALSE,kFALSE);

    // reading input files and declaring containers
    Bool_t ret = kFALSE;
    if(infileList.Contains(",")){
        ret = loop.addMultFiles(infileList); // file1,file2,file3
    } else{
        ret = loop.addFiles(infileList); // myroot*.root
    }

    if(ret == 0) {
        cerr<<"READBACK: ERROR : cannot find inputfiles : "<<infileList.Data()<<endl;
        return 1;
    }

    //if(!loop.setInput("")) {   // all input categories
    if(!loop.setInput("-*,+HParticleCand,+HParticleEvtInfo,+HWallHit")) {
        cerr<<"READBACK: ERROR : cannot read input !"<<endl;
        exit(1);
    }
    // read all categories
    loop.printCategories();
    loop.printChain();
    
    //parameters
    HEnergyLossCorrPar dEdxCorr;
    dEdxCorr.setDefaultPar("apr12");

    // input data
    HCategory* candCat    = (HCategory*)HCategoryManager::getCategory(catParticleCand);
    HCategory* evtInfoCat = (HCategory*)HCategoryManager::getCategory(catParticleEvtInfo);
    HCategory* wallCat    = (HCategory*)HCategoryManager::getCategory(catWallHit);

    /*//evtchara setup for cetrality determintaion 
    HParticleEvtChara evtChara;
    evtChara.setBeamTime("apr12");
    evtChara.setGeneration("gen8");
    evtChara.useEstimator("SelcTrackCorr");
    evtChara.init();
    evtChara.printCentralityClass();   */ 
    
    
    //#######################################################################
    //#######################################################################

    // ###### ######  #####  #####
    //   ##   ##  ##  ##     ##   
    //   ##   #####   #####  #####
    //   ##   ## ##   ##     ##
    //   ##   ##  ##  #####  #####
    //-----------------------------------------------------------------------
    const Short_t nWallSubEvents = 6;        //number of FW subevents
    const Short_t nWallRandomSubEvents = 10; //number of random FW subevents
    const Short_t nMdcSubEvents = 3;         //number of MDC subevents 
    const Short_t nHarmonics = 2;            //number of harmonics for q-vectors
    Short_t nWallHitsTot;                    //total number of FW hits

    Float_t wallQx[nWallSubEvents][nHarmonics];  //Q vector x component of FW subevent
    Float_t wallQy[nWallSubEvents][nHarmonics];  //Q vector y component of FW subevent
    Float_t wallQw[nWallSubEvents];              //weight of Q-vector
    Float_t wallQxRandom[nWallRandomSubEvents][nHarmonics];  //Q vector x component of random FW subevent
    Float_t wallQyRandom[nWallRandomSubEvents][nHarmonics];  //Q vector y component of random FW subevent
    Float_t wallQwRandom[nWallRandomSubEvents];              //weight of Q-vector
    Float_t mdcQx[nMdcSubEvents][nHarmonics];  //Q vector x component of MDC subevent
    Float_t mdcQy[nMdcSubEvents][nHarmonics];  //Q vector y component of MDC subevent
    Float_t mdcQw[nMdcSubEvents];              //weight of Q-vector
    
    //FW hits
    const Short_t maxNWallHits = 200;        //maximal number of FW hits
    Short_t wallModuleIndex[maxNWallHits];   //index of hit module
    Float_t wallHitTime[maxNWallHits];       //time of FW hit
    Float_t wallHitCharge[maxNWallHits];     //charge of FW hit
    Float_t wallHitDistance[maxNWallHits];   //distance to FW module
    Short_t wallHitRing[maxNWallHits];       //wall ring of a hit
    Float_t wallHitPhi[maxNWallHits];        //phi angle of hit module in rad
    Bool_t  isWallHitOk[maxNWallHits];       //output of hit cuts
    
    //MDC
    Short_t nTracks = 0;    //number of all tracks in MDC
    Short_t nProtons = 0;   //number of protons
    Short_t nPiP = 0;       //number of pi+
    Short_t nPiM = 0;       //number of pi-

    //Vertex
    Float_t vX;      //x coordinate of primary vertex
    Float_t vY;      //y coordinate of primary vertex
    Float_t vZ;      //z coordinate of primary vertex
    Float_t vChi2;   //vertex reconstruction chi^2 

    //centrality
    Float_t centralityMdc;
    Float_t centralityTofRpc;
    Float_t centralityWallCharge;
    
    //Time
    Int_t time;

    //tracks
    const Short_t maxNTracks = 200;
    Short_t pid[maxNTracks];
    Float_t p[maxNTracks];
    Float_t phi[maxNTracks];
    Float_t theta[maxNTracks];
    Float_t pt[maxNTracks];
    Float_t rapidity[maxNTracks];
    Float_t beta[maxNTracks];
    Float_t mass[maxNTracks];
    Short_t charge[maxNTracks];
    Float_t dEdxMdc[maxNTracks];
    Float_t dEdxTof[maxNTracks];
    Float_t rToBeam[maxNTracks];
    Float_t zToBeam[maxNTracks];
    Short_t nMdcHits[maxNTracks];
    Float_t chi2[maxNTracks];
    Float_t chi2inner[maxNTracks];
    Float_t chi2outer[maxNTracks];
    Float_t metaMatchQuality[maxNTracks];
    Float_t metaMatchRadius[maxNTracks];
    Float_t p_corr[maxNTracks];
    Float_t pt_corr[maxNTracks];
    Float_t rapidity_corr[maxNTracks];
    
    //variables for cuts
    Bool_t trigger;
    Bool_t vertexClust;
    Bool_t vertexCand;
    Bool_t goodSTART;
    Bool_t noPileUpSTART;
    Bool_t noVETO;
    Bool_t goodSTARTVETO;
    Bool_t goodSTARTMETA;
    Bool_t isgoodEvent;
            
    TFile* out = new TFile(outfile.Data(),"RECREATE");
    out->cd();

    TTree* tree = new TTree("tree", "HADES Au+Au 1.23 GeV 8gen tree for flow analysis");
    
    tree->Branch("nWallHitsTot",  &nWallHitsTot,  "nWallHitsTot/S");
    tree->Branch("wallQx",        wallQx,         "wallQx[6][2]/F");     
    tree->Branch("wallQy",        wallQy,         "wallQy[6][2]/F");
    tree->Branch("wallQw",        wallQw,         "wallQw[6]/F");
    tree->Branch("wallQxRandom",  wallQxRandom,   "wallQxRandom[10][2]/F");     
    tree->Branch("wallQyRandom",  wallQyRandom,   "wallQyRandom[10][2]/F");
    tree->Branch("wallQwRandom",  wallQwRandom,   "wallQwRandom[10]/F");
    tree->Branch("mdcQx",  mdcQx,   "mdcQx[3][2]/F");     
    tree->Branch("mdcQy",  mdcQy,   "mdcQy[3][2]/F");
    tree->Branch("mdcQw",  mdcQw,   "mdcQw[3]/F");    
    
    //FW hits
    tree->Branch("wallModuleIndex", wallModuleIndex, "wallModuleIndex[nWallHitsTot]/S");
    tree->Branch("wallHitTime",     wallHitTime,     "wallHitTime[nWallHitsTot]/F");  
    tree->Branch("wallHitCharge",   wallHitCharge,   "wallHitCharge[nWallHitsTot]/F");
    tree->Branch("wallHitDistance", wallHitDistance, "wallHitDistance[nWallHitsTot]/F");
    tree->Branch("wallHitRing",     wallHitRing,     "wallHitRing[nWallHitsTot]/S");
    tree->Branch("wallHitPhi",      wallHitPhi,      "wallHitPhi[nWallHitsTot]/F");
    tree->Branch("isWallHitOk",     isWallHitOk,     "isWallHitOk[nWallHitsTot]/O");
     
    //MDC 
    tree->Branch("nTracks",  &nTracks,  "nTracks/S"); 
    tree->Branch("nProtons", &nProtons, "nProtons/S");
    tree->Branch("nPiP",     &nPiP,     "nPiP/S");    
    tree->Branch("nPiM",     &nPiM,     "nPiM/S");     
    
    //Vertex
    tree->Branch("vX",    &vX,    "vX/F");   
    tree->Branch("vY",    &vY,    "vY/F");   
    tree->Branch("vZ",    &vZ,    "vZ/F");   
    tree->Branch("vChi2", &vChi2, "vChi2/F");
    
    //Centrality    
    tree->Branch("centralityMdc",  &centralityMdc,  "centralityMdc/F");
    tree->Branch("centralityTofRpc",  &centralityTofRpc,  "centralityTofRpc/F");
    tree->Branch("centralityWallCharge", &centralityWallCharge, "centralityWallCharge/F");
    
    //Time
    tree->Branch("time", &time, "time/I");
    
    //Tracks
    tree->Branch("pid",      pid,      "pid[nTracks]/S");
    tree->Branch("p",        p,        "p[nTracks]/F");
    tree->Branch("phi",      phi,      "phi[nTracks]/F");
    tree->Branch("theta",    theta,    "theta[nTracks]/F");
    tree->Branch("pt",       pt,       "pt[nTracks]/F");
    tree->Branch("rapidity", rapidity, "rapidity[nTracks]/F");
    tree->Branch("beta",     beta,     "beta[nTracks]/F");
    tree->Branch("mass",     mass,     "mass[nTracks]/F");
    tree->Branch("charge",   charge,   "charge[nTracks]/S");
    tree->Branch("dEdxMdc",  dEdxMdc,  "dEdxMdc[nTracks]/F");
    tree->Branch("dEdxTof",  dEdxTof,  "dEdxTof[nTracks]/F");
    tree->Branch("rToBeam",  rToBeam,  "rToBeam[nTracks]/F");
    tree->Branch("zToBeam",  zToBeam,  "zToBeam[nTracks]/F");
    tree->Branch("nMdcHits", nMdcHits, "nMdcHits[nTracks]/S");
    tree->Branch("chi2",     chi2,     "chi2[nTracks]/F");
    tree->Branch("chi2inner",chi2inner,"chi2inner[nTracks]/F");
    tree->Branch("chi2outer",chi2outer,"chi2outer[nTracks]/F");
    tree->Branch("metaMatchQuality", metaMatchQuality, "metaMatchQuality[nTracks]/F");
    tree->Branch("metaMatchRadius",  metaMatchRadius,  "metaMatchRadius[nTracks]/F");
    tree->Branch("p_corr",   p_corr,   "p_corr[nTracks]/F");
    tree->Branch("pt_corr",  pt_corr,  "pt_corr[nTracks]/F");
    tree->Branch("rapidity_corr",rapidity_corr,"rapidity_corr[nTracks]/F");
    
    //Cuts
    tree->Branch("trigger",             trigger,            "trigger/O");
    tree->Branch("vertexClust",         vertexClust,        "vertexClust/O");
    tree->Branch("vertexCand",          vertexCand,         "vertexCand/O");
    tree->Branch("goodSTART",           goodSTART,          "tgoodSTART/O");
    tree->Branch("noPileUpSTART",       noPileUpSTART,      "noPileUpSTART/O");
    tree->Branch("noVETO",              noVETO,             "noVETO/O");
    tree->Branch("goodSTARTVETO",       goodSTARTVETO,      "goodSTARTVETO/O");
    tree->Branch("goodSTARTMETA",       goodSTARTMETA,      "goodSTARTMETA/O");
    tree->Branch("isgoodEvent",         isgoodEvent,        "isgoodEvent/O");
    

    //#######################################################################
    //#######################################################################

    //##      #######  #######  #####
    //##      ##   ##  ##   ##  ##  ## 
    //##      ##   ##  ##   ##  #####
    //##      ##   ##  ##   ##  ##
    //######  #######  #######  ##
    //-----------------------------------------------------------------------
    
    Int_t entries = loop.getEntries();
    if(nEvents < entries && nEvents >= 0 ) entries = nEvents;
    TString filename;
    Int_t sectors [6];
    MHWallDivider* divider = new MHWallDivider();
    TRandom2 *randomGenerator = new TRandom2();
    Float_t rndm;

    for (Int_t i = 0; i < entries; i++) {
        Int_t nbytes =  loop.nextEvent(i);             // get next event. categories will be cleared before
        if(nbytes <= 0) { cout<<nbytes<<endl; break; } // last event reached
        if(i%5000 == 0) cout<<"event "<<i<<endl;

        loop.getSectors(sectors); // fill sector array
        
        Int_t g, day, hour, minute;
        TString* be = new TString("be");
        
        if(loop.isNewFile(filename)){
            if(!isSimulation) filename = HTime::stripFileName(filename,kTRUE,kFALSE);
            HTime::splitFileName(filename,*be,g,day,hour,minute,g,g,kFALSE);
            time = day*24*60 + hour*24 + minute;
        }
        
        //-------------------------------------------------
        // summary event info object
        HParticleEvtInfo* evtInfo=0;
        evtInfo = HCategoryManager::getObject(evtInfo,evtInfoCat,0 );

        trigger = evtInfo->isGoodEvent(Particle::kGoodTRIGGER);
        vertexClust = evtInfo->isGoodEvent(Particle::kGoodVertexClust);
        vertexCand = evtInfo->isGoodEvent(Particle::kGoodVertexCand);
        goodSTART = evtInfo->isGoodEvent(Particle::kGoodSTART);
        noPileUpSTART = evtInfo->isGoodEvent(Particle::kNoPileUpSTART);
        noVETO = evtInfo->isGoodEvent(Particle::kNoVETO);
        goodSTARTVETO = evtInfo->isGoodEvent(Particle::kGoodSTARTVETO);
        goodSTARTMETA = evtInfo->isGoodEvent(Particle::kGoodSTARTMETA);
        
        isgoodEvent = (trigger && vertexClust && vertexCand && goodSTART && noPileUpSTART 
                                            && noVETO && goodSTARTMETA && goodSTARTVETO);


        if ( evtInfo&&!evtInfo->isGoodEvent(Particle::kGoodTRIGGER|
                                        Particle::kGoodVertexClust|
                                        Particle::kGoodVertexCand|
                                        Particle::kGoodSTART|
                                        Particle::kNoPileUpSTART|
                                        Particle::kNoVETO|
                                        Particle::kGoodSTARTVETO|
                                        Particle::kGoodSTARTMETA) ) continue;
        
        
        //get primary vertex
        HVertex vertexReco = gHades->getCurrentEvent()->getHeader()->getVertexReco();
        
        vX = vertexReco.getX();
        vY = vertexReco.getY();
        vZ = vertexReco.getZ();
        vChi2 = vertexReco.getChi2();

        //centrality
        /*evtChara.execute();
        centralityMdc = evtChara.getCentralityPercentile("SelcTrackCorr");
        centralityTofRpc = evtChara.getCentralityPercentile("TOFRPCtimecut");
        centralityWallCharge = evtChara.getCentralityPercentile("FWSumChargeSpec");     */
        
        // loop over FW hits
        HWallHit* wallHit = 0;
        
        nWallHitsTot = wallCat->getEntries();
        if (nWallHitsTot>maxNWallHits) {
            cerr << "ERROR: nWallHitsTot="<<nWallHitsTot<<" > maxNWallHits="<<maxNWallHits<<endl;
            return 1;
        }
                       
        for (Short_t isub=0; isub<nWallSubEvents; isub++) {
            wallQw[isub]=0;
            for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                wallQx[isub][iharm]=0;       
                wallQy[isub][iharm]=0;
            }
        }
        
        for (Short_t irsub=0; irsub<nWallRandomSubEvents; irsub++) {
            wallQwRandom[irsub]=0;
            for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                wallQxRandom[irsub][iharm]=0;       
                wallQyRandom[irsub][iharm]=0;
            }
        }

        for (Short_t isub=0; isub<nMdcSubEvents; isub++) {
            mdcQw[isub]=0;
            for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                mdcQx[isub][iharm]=0;       
                mdcQy[isub][iharm]=0;
            }
        } 
        
        Short_t subevent;
        Short_t ring;
        Float_t psi;
        Short_t randomSubEvent;
        Float_t hit_beta;
        //for A.Sadovsky method:
        Int_t nA = 0;
        Int_t nB = 0;
        
        for(Short_t j=0; j<nWallHitsTot; j++) {
            wallHit = HCategoryManager::getObject(wallHit,wallCat,j);
            
            wallModuleIndex[j] = wallHit->getCell();
            wallHitTime[j] = wallHit->getTime();
            wallHitCharge[j] = wallHit->getCharge();
            wallHitDistance[j] = wallHit->getDistance();
            isWallHitOk[j] = kFALSE;
            wallHitRing[j] = divider->GetRing(wallModuleIndex[j]);
            ring = wallHitRing[j];
            if (ring==-1) {
                cerr << "Error in short MHWallDivider::GetRing(short i="<<wallModuleIndex[j]<<"): it's returned -1" << endl;
                return 2;
            }
            subevent = divider->GetSubEvent(wallModuleIndex[j]);

            //wallHit->getXYZLab(cellX, cellY, cellZ);
            
            psi = wallHit->getPhi() * D2R;
            wallHitPhi[j] = psi;
            
            //cuts by B.Kardan
            hit_beta = wallHitDistance[j]/wallHitTime[j]/299.792458;
            if ( (ring<=4            && wallHitCharge[j]>80 && hit_beta>0.84 && hit_beta<1.) ||
                 ((ring==5||ring==6) && wallHitCharge[j]>85 && hit_beta>0.85 && hit_beta<1.) ||
                 (ring>6             && wallHitCharge[j]>86 && hit_beta>0.80 && hit_beta<1.) ) {
                
                isWallHitOk[j] = kTRUE;
                
                //Q vectors
                //Wall Subevents
                if (subevent==-1) continue;
                //WallRing1_9
                for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                    wallQx[0][iharm]+= TMath::Cos((iharm+1)*psi);       
                    wallQy[0][iharm]+= TMath::Sin((iharm+1)*psi);
                }
                wallQw[0]++;

                //WallRing7_9
                if (subevent==1) {
                    for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                        wallQx[1][iharm]+= TMath::Cos((iharm+1)*psi);       
                        wallQy[1][iharm]+= TMath::Sin((iharm+1)*psi);
                    }
                    wallQw[1]++;
                }

                //Other wall subevents
                if (subevent>1) {
                    for (short s = subevent; s>=2; s--) {
                        for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                            wallQx[s][iharm]+= TMath::Cos((iharm+1)*psi);       
                            wallQy[s][iharm]+= TMath::Sin((iharm+1)*psi);
                        }
                        wallQw[s]++;
                    }
                }
                
                rndm = randomGenerator->Rndm();
                //Random Wall Subevents
                randomSubEvent = (rndm<0.5) ? 0 : 1;
                for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                    wallQxRandom[randomSubEvent][iharm]+= TMath::Cos((iharm+1)*psi);       
                    wallQyRandom[randomSubEvent][iharm]+= TMath::Sin((iharm+1)*psi);
                }
                wallQwRandom[randomSubEvent]++;

                //Random Wall Subevents by A.Sadovsky
                Float_t level = (0.5*nWallHitsTot - nA)/((Float_t)(nWallHitsTot-nA-nB));
                randomSubEvent = (rndm<level) ? 2 : 3;
                for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                    wallQxRandom[randomSubEvent][iharm]+= TMath::Cos((iharm+1)*psi);       
                    wallQyRandom[randomSubEvent][iharm]+= TMath::Sin((iharm+1)*psi);
                }
                wallQwRandom[randomSubEvent]++;
                if (randomSubEvent==2) nA++;
                else nB++;

                //Chequerwise Wall Subevents
                randomSubEvent = (wallModuleIndex[j]%2==0) ? 4 : 5;
                for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                    wallQxRandom[randomSubEvent][iharm]+= TMath::Cos((iharm+1)*psi);
                    wallQyRandom[randomSubEvent][iharm]+= TMath::Sin((iharm+1)*psi);
                }
                wallQwRandom[randomSubEvent]++;

                //Ring7_9Random
                if (ring>6) {
                    randomSubEvent = (rndm<0.5) ? 6 : 7;
                    for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                        wallQxRandom[randomSubEvent][iharm]+= TMath::Cos((iharm+1)*psi);       
                        wallQyRandom[randomSubEvent][iharm]+= TMath::Sin((iharm+1)*psi);
                    }
                    wallQwRandom[randomSubEvent]++;
                }
                //Ring1_6Random
                if (ring>=1&&ring<=6) {
                    randomSubEvent = (rndm<0.5) ? 8 : 9;
                    for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                        wallQxRandom[randomSubEvent][iharm]+= TMath::Cos((iharm+1)*psi);       
                        wallQyRandom[randomSubEvent][iharm]+= TMath::Sin((iharm+1)*psi);
                    }
                    wallQwRandom[randomSubEvent]++;
                }
            }//B.Kardan cuts for wall hits
        }//loop over wall hits
        
        for (Short_t isub=0; isub<nWallSubEvents; isub++) {
            if (wallQw[isub]==0) continue;
            for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                wallQx[isub][iharm] = wallQx[isub][iharm] / wallQw[isub];       
                wallQy[isub][iharm] = wallQy[isub][iharm] / wallQw[isub]; 
            }
        }
        
        for (Short_t irsub=0; irsub<nWallRandomSubEvents; irsub++) {
            if (wallQwRandom[irsub]==0) continue;
            for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                wallQxRandom[irsub][iharm] = wallQxRandom[irsub][iharm] / wallQwRandom[irsub];       
                wallQyRandom[irsub][iharm] = wallQyRandom[irsub][iharm] / wallQwRandom[irsub]; 
            }
        }
        
        
        // loop over particle candidates in event
        nTracks = 0;
        nProtons = 0;
        nPiM = 0;
        nPiP = 0;
        if(!candCat) continue;
        Int_t size = candCat->getEntries();
        HParticleCand* cand=0;
        Int_t itr;
        for(Int_t j = 0; j < size; j++) {
            cand = HCategoryManager::getObject(cand,candCat,j);
            if(!cand) continue;
            if(!loop.goodSector(cand->getSector())) { continue;}  // skip inactive sectors
            if(!cand->isFlagBit(kIsUsed)) continue;
            if( cand->getMomentum() == cand->getMomentumOrg() ) continue; //skip tracks with too high pt
            itr = nTracks;
            pid[itr] = cand->getPID();
            p[itr] = cand->getMomentum();
            theta[itr] = cand->getTheta()*D2R;
            pt[itr] = p[itr] * TMath::Sin( theta[itr] ); 
            mass[itr] = cand->getMass();
            Float_t pz = p[itr] * TMath::Cos( theta[itr] );
            Float_t e_lab = TMath::Sqrt( mass[itr]*mass[itr] + p[itr]*p[itr] );
            rapidity[itr] = 0.5 * TMath::Log( (e_lab + pz)/(e_lab - pz) ) - Y_BEAM;
            
            if (pid[itr]>=0) {
                p_corr[itr] = cand->getCorrectedMomentumPID(pid[itr]);        // retrieve corrected mom
                cand->setMomentum(p_corr[itr]);                                   // write it back
                cand->calc4vectorProperties(HPhysicsConstants::mass(pid[itr]));   // sync with lorentz vector
            }
            
            p_corr[itr] = cand->getMomentum();
            pt_corr[itr] = p_corr[itr] * TMath::Sin( theta[itr] );                        
            phi[itr] = cand->getPhi()*D2R;
            beta[itr] = cand->getBeta();
            charge[itr] = cand->getCharge();
            nMdcHits[itr] = cand->getNLayer(2);//inner+outer
            dEdxMdc[itr] = cand->getMdcdEdx();
            dEdxTof[itr] = cand->getTofdEdx();
            rToBeam[itr] = cand->getR();
            zToBeam[itr] = cand->getZ();
            chi2[itr] = cand->getChi2();
            chi2inner[itr] = cand->getInnerSegmentChi2();
            chi2outer[itr] = cand->getOuterSegmentChi2();
            metaMatchQuality[itr] = cand->getMetaMatchQuality();
            metaMatchRadius[itr] = cand->getMetaMatchRadius();
            pz = p_corr[itr] * TMath::Cos( theta[itr] );
            Float_t pidMass = (pid[itr]>=0) ? HPhysicsConstants::mass(pid[itr]) : mass[itr];
            e_lab = TMath::Sqrt( pidMass*pidMass + p_corr[itr]*p_corr[itr] );
            rapidity_corr[itr] = 0.5 * TMath::Log( (e_lab + pz)/(e_lab - pz) ) - Y_BEAM;

            if( pid[itr]==14 ) nProtons++;
            if( pid[itr]==8 )  nPiP++;
            if( pid[itr]==9 )  nPiM++;
            
            nTracks++;
            if (nTracks >= maxNTracks) {
                cerr << "ERROR: nTracks > maxNTracks=="<<maxNTracks<<endl;
                return 3;
            }

            //track cuts for MDC Q-vectors
            if ( pid[itr]==14 && pt_corr[itr]>250 && pt_corr[itr]<1700 &&
                 TMath::Abs(zToBeam[itr]-vZ)<15. && TMath::Abs(rToBeam[itr])<15. &&
                 beta[itr]<1 && mass[itr]>600 && mass[itr]<1200) {

                Short_t mdcSubEvent=-1;
                if (rapidity_corr[itr]>-0.7&&rapidity_corr[itr]<-0.2) mdcSubEvent=0;
                if (rapidity_corr[itr]>-0.7&&rapidity_corr[itr]<-0.4) mdcSubEvent=1;
                if (rapidity_corr[itr]>0.2&&rapidity_corr[itr]<0.7) mdcSubEvent=2;
                if (mdcSubEvent>-1) {
                    for (Short_t iharm = 0; iharm<nHarmonics; iharm++) {
                        mdcQx[mdcSubEvent][iharm] += TMath::Cos((iharm+1)*phi[itr]);
                        mdcQy[mdcSubEvent][iharm] += TMath::Sin((iharm+1)*phi[itr]);
                    }
                    mdcQw[mdcSubEvent]++;
                }
            }       

        } // end cand loop

        for (Short_t isub=0; isub<nMdcSubEvents; isub++) {
            if (mdcQw[isub]==0) continue;
            Float_t sign = (isub==2) ? 1 : -1;
            for (Short_t iharm=0; iharm<nHarmonics; iharm++) {
                mdcQx[isub][iharm] = sign * mdcQx[isub][iharm] / mdcQw[isub];       
                mdcQy[isub][iharm] = sign * mdcQy[isub][iharm] / mdcQw[isub]; 
            }
        }
        
        tree->Fill(); 
        
    } // end eventloop

    tree->Write();
    //out->Save();
    out->Close();
    
    delete gHades;
    return 0;
}

int main(int argc, char **argv)
{
    TROOT Analysis("Analysis","compiled analysis macro");

    // argc is the number of arguments in char* array argv
    // CAUTION: argv[0] contains the progname
    // argc has to be nargs+1

    TString nevts ;
    TString filenumber;
    switch (argc) {
    case 4:       // just inputfile name + nArgs
        nevts  = argv[3];
        return makeTree(TString(argv[1]),TString(argv[2]), nevts.Atoi());
        break;
    default:
        cerr<<"ERROR: loopDST() : WRONG NUMBER OF ARGUMENTS! TString infile="",TString outfile="", nevents=-1"<<endl;
        return 1; // fail
    }
}
