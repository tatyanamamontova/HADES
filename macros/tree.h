//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov 23 13:51:33 2017 by ROOT version 5.34/34
// from TTree tree/HADES Au+Au 1.23 GeV 8gen tree for flow analysis
// found on file: tree_12108160806.root
//////////////////////////////////////////////////////////

#ifndef tree_h
#define tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           nRpcClust;
   Int_t           nRpcClustCut;
   Int_t           nTofHits;
   Int_t           nTofHitsCut;
   Int_t           primaryTracks;
   Int_t           selectedTracks;
   Bool_t          trigInd[4];
   Short_t         runId;
   Bool_t          cuts[8];
   Short_t         wallModuleIndex[200];
   Short_t         wallHitTime[200];
   Short_t         wallHitCharge[200];
   Short_t         wallHitDistance[200];
   Short_t         wallHitRing[200];
   Short_t         wallHitPhi[200];
   Short_t         isWallHitOk[200];
   Short_t         wallChargeTot_mod[304];
   Float_t         wallChargeTot;
   Short_t         wallChargeTot_ring[9];
   Short_t         nTracks;
   Short_t         nProtons;
   Short_t         nPiP;
   Short_t         nPiM;
   Float_t         vX;
   Float_t         vY;
   Float_t         vZ;
   Float_t         vChi2;
   Int_t           time;
   Short_t         pid[105];   //[nTracks]
   Float_t         p[105];   //[nTracks]
   Float_t         phi[105];   //[nTracks]
   Float_t         theta[105];   //[nTracks]
   Float_t         pt[105];   //[nTracks]
   Float_t         rapidity[105];   //[nTracks]
   Float_t         beta[105];   //[nTracks]
   Float_t         mass[105];   //[nTracks]
   Short_t         charge[105];   //[nTracks]
   Float_t         dEdxMdc[105];   //[nTracks]
   Float_t         dEdxTof[105];   //[nTracks]
   Float_t         rToBeam[105];   //[nTracks]
   Float_t         zToBeam[105];   //[nTracks]
   Short_t         nMdcHits[105];   //[nTracks]
   Float_t         chi2[105];   //[nTracks]
   Float_t         chi2inner[105];   //[nTracks]
   Float_t         chi2outer[105];   //[nTracks]
   Float_t         metaMatchQuality[105];   //[nTracks]
   Float_t         metaMatchRadius[105];   //[nTracks]
   Float_t         p_corr[105];   //[nTracks]
   Float_t         pt_corr[105];   //[nTracks]
   Float_t         rapidity_corr[105];   //[nTracks]

   // List of branches
   TBranch        *b_nRpcClust;   //!
   TBranch        *b_nRpcClustCut;   //!
   TBranch        *b_nTofHits;   //!
   TBranch        *b_nTofHitsCut;   //!
   TBranch        *b_primaryTracks;   //!
   TBranch        *b_selectedTracks;   //!
   TBranch        *b_trigInd;   //!
   TBranch        *b_runId;   //!
   TBranch        *b_cuts;   //!
   TBranch        *b_wallModuleIndex;   //!
   TBranch        *b_wallHitTime;   //!
   TBranch        *b_wallHitCharge;   //!
   TBranch        *b_wallHitDistance;   //!
   TBranch        *b_wallHitRing;   //!
   TBranch        *b_wallHitPhi;   //!
   TBranch        *b_isWallHitOk;   //!
   TBranch        *b_wallChargeTot_mod;   //!
   TBranch        *b_wallChargeTot;   //!
   TBranch        *b_wallChargeTot_ring;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_nProtons;   //!
   TBranch        *b_nPiP;   //!
   TBranch        *b_nPiM;   //!
   TBranch        *b_vX;   //!
   TBranch        *b_vY;   //!
   TBranch        *b_vZ;   //!
   TBranch        *b_vChi2;   //!
   TBranch        *b_time;   //!
   TBranch        *b_pid;   //!
   TBranch        *b_p;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_theta;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_rapidity;   //!
   TBranch        *b_beta;   //!
   TBranch        *b_mass;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_dEdxMdc;   //!
   TBranch        *b_dEdxTof;   //!
   TBranch        *b_rToBeam;   //!
   TBranch        *b_zToBeam;   //!
   TBranch        *b_nMdcHits;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_chi2inner;   //!
   TBranch        *b_chi2outer;   //!
   TBranch        *b_metaMatchQuality;   //!
   TBranch        *b_metaMatchRadius;   //!
   TBranch        *b_p_corr;   //!
   TBranch        *b_pt_corr;   //!
   TBranch        *b_rapidity_corr;   //!

   tree(TTree *tree=0);
   virtual ~tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tree_cxx
tree::tree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("tree_12108160806.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("tree_12108160806.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

tree::~tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nRpcClust", &nRpcClust, &b_nRpcClust);
   fChain->SetBranchAddress("nRpcClustCut", &nRpcClustCut, &b_nRpcClustCut);
   fChain->SetBranchAddress("nTofHits", &nTofHits, &b_nTofHits);
   fChain->SetBranchAddress("nTofHitsCut", &nTofHitsCut, &b_nTofHitsCut);
   fChain->SetBranchAddress("primaryTracks", &primaryTracks, &b_primaryTracks);
   fChain->SetBranchAddress("selectedTracks", &selectedTracks, &b_selectedTracks);
   fChain->SetBranchAddress("trigInd", trigInd, &b_trigInd);
   fChain->SetBranchAddress("runId", &runId, &b_runId);
   fChain->SetBranchAddress("cuts", cuts, &b_cuts);
   fChain->SetBranchAddress("wallModuleIndex", wallModuleIndex, &b_wallModuleIndex);
   fChain->SetBranchAddress("wallHitTime", wallHitTime, &b_wallHitTime);
   fChain->SetBranchAddress("wallHitCharge", wallHitCharge, &b_wallHitCharge);
   fChain->SetBranchAddress("wallHitDistance", wallHitDistance, &b_wallHitDistance);
   fChain->SetBranchAddress("wallHitRing", wallHitRing, &b_wallHitRing);
   fChain->SetBranchAddress("wallHitPhi", wallHitPhi, &b_wallHitPhi);
   fChain->SetBranchAddress("isWallHitOk", isWallHitOk, &b_isWallHitOk);
   fChain->SetBranchAddress("wallChargeTot_mod", wallChargeTot_mod, &b_wallChargeTot_mod);
   fChain->SetBranchAddress("wallChargeTot", &wallChargeTot, &b_wallChargeTot);
   fChain->SetBranchAddress("wallChargeTot_ring", wallChargeTot_ring, &b_wallChargeTot_ring);
   fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
   fChain->SetBranchAddress("nProtons", &nProtons, &b_nProtons);
   fChain->SetBranchAddress("nPiP", &nPiP, &b_nPiP);
   fChain->SetBranchAddress("nPiM", &nPiM, &b_nPiM);
   fChain->SetBranchAddress("vX", &vX, &b_vX);
   fChain->SetBranchAddress("vY", &vY, &b_vY);
   fChain->SetBranchAddress("vZ", &vZ, &b_vZ);
   fChain->SetBranchAddress("vChi2", &vChi2, &b_vChi2);
   fChain->SetBranchAddress("time", &time, &b_time);
   fChain->SetBranchAddress("pid", pid, &b_pid);
   fChain->SetBranchAddress("p", p, &b_p);
   fChain->SetBranchAddress("phi", phi, &b_phi);
   fChain->SetBranchAddress("theta", theta, &b_theta);
   fChain->SetBranchAddress("pt", pt, &b_pt);
   fChain->SetBranchAddress("rapidity", rapidity, &b_rapidity);
   fChain->SetBranchAddress("beta", beta, &b_beta);
   fChain->SetBranchAddress("mass", mass, &b_mass);
   fChain->SetBranchAddress("charge", charge, &b_charge);
   fChain->SetBranchAddress("dEdxMdc", dEdxMdc, &b_dEdxMdc);
   fChain->SetBranchAddress("dEdxTof", dEdxTof, &b_dEdxTof);
   fChain->SetBranchAddress("rToBeam", rToBeam, &b_rToBeam);
   fChain->SetBranchAddress("zToBeam", zToBeam, &b_zToBeam);
   fChain->SetBranchAddress("nMdcHits", nMdcHits, &b_nMdcHits);
   fChain->SetBranchAddress("chi2", chi2, &b_chi2);
   fChain->SetBranchAddress("chi2inner", chi2inner, &b_chi2inner);
   fChain->SetBranchAddress("chi2outer", chi2outer, &b_chi2outer);
   fChain->SetBranchAddress("metaMatchQuality", metaMatchQuality, &b_metaMatchQuality);
   fChain->SetBranchAddress("metaMatchRadius", metaMatchRadius, &b_metaMatchRadius);
   fChain->SetBranchAddress("p_corr", p_corr, &b_p_corr);
   fChain->SetBranchAddress("pt_corr", pt_corr, &b_pt_corr);
   fChain->SetBranchAddress("rapidity_corr", rapidity_corr, &b_rapidity_corr);
   Notify();
}

Bool_t tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tree_cxx
