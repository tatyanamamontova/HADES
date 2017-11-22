//@brief Scripts for drawing cuts variables
//@author T.Mamontova
//@date 20.11.17
//@param tree without .root
//@return pics with histos

#include "TTree.h"
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include <TNtuple.h>
#include "TFile.h"
#include "TChain.h"

void DrawCuts(char* input) {

TChain *ch = new TChain;
char picName[200];
char trees[200];
sprintf(trees, "%s.root/tree", input);
ch->Add(trees);

TH1F* hTrig = new TH1F("hTrig", "Trigger cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hVClust = new TH1F("hVClust", "VertexClust cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hVCand = new TH1F("hVCand", "VertexCand cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hGoodSTART = new TH1F("hGoodSTART ", "GoodSTART cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hNoPileUpSTART = new TH1F("hNoPileUpSTART", "NoPileUpSTART cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hNoVETO = new TH1F("hNoVETO", "NoVETO cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hGoodSTARTVETO = new TH1F("hGoodSTARTVETO", "GoodSTARTVETO cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hGoodSTARTMETA = new TH1F("hGoodSTARTMETA", "GoodSTARTMETA cut; True/False; Events", 2, -0.5, 1.5);
TH1F* hisgoodEvent = new TH1F("hisgoodEvent", "All cuts; True/False; Events", 2, -0.5, 1.5);

Bool_t trigger;
Bool_t vertexClust;
Bool_t vertexCand;
Bool_t goodSTART;
Bool_t noPileUpSTART;
Bool_t noVETO;
Bool_t goodSTARTVETO;
Bool_t goodSTARTMETA;
Bool_t isgoodEvent;

ch->SetBranchAddress("trigger",             &trigger);
ch->SetBranchAddress("vertexClust",         &vertexClust);
ch->SetBranchAddress("vertexCand",          &vertexCand);
ch->SetBranchAddress("goodSTART",           &goodSTART);
ch->SetBranchAddress("noPileUpSTART",       &noPileUpSTART);
ch->SetBranchAddress("noVETO",              &noVETO);
ch->SetBranchAddress("goodSTARTVETO",       &goodSTARTVETO);
ch->SetBranchAddress("goodSTARTMETA",       &goodSTARTMETA);
ch->SetBranchAddress("isgoodEvent",         &isgoodEvent);


int entry=0;
while(entry < ch->GetEntries()) {
    ch->GetEntry(entry);

    hTrig->Fill(trigger);
    hVClust->Fill(vertexClust);
    hVCand->Fill(vertexCand);
    hGoodSTART->Fill(goodSTART);
    hNoPileUpSTART->Fill(noPileUpSTART);
    hNoVETO->Fill(noVETO);
    hGoodSTARTVETO->Fill(goodSTARTVETO);
    hGoodSTARTMETA->Fill(goodSTARTMETA);
    hisgoodEvent->Fill(isgoodEvent);

    entry++;
}

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hTrig->Draw();
sprintf(picName, "./pics/trig_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/trig_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hVClust->Draw();
sprintf(picName, "./pics/VClust_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/hVClust_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hVCand->Draw();
sprintf(picName, "./pics/VCand_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/VCand_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hGoodSTART->Draw();
sprintf(picName, "./pics/GoodSTART_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/GoodSTART_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hNoPileUpSTART->Draw();
sprintf(picName, "./pics/NoPileUpSTART_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/NoPileUpSTART_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hNoVETO->Draw();
sprintf(picName, "./pics/NoVETO_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/NoVETO_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hGoodSTARTVETO->Draw();
sprintf(picName, "./pics/GoodSTARTVETO_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/GoodSTARTVETO_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hGoodSTARTMETA->Draw();
sprintf(picName, "./pics/GoodSTARTMETA_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/GoodSTARTMETA_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
hisgoodEvent->Draw();
sprintf(picName, "./pics/isgoodEvent_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/isgoodEvent_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;

}


