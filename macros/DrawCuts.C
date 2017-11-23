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

const Short_t nCuts = 8;
Bool_t cuts[nCuts];

ch->SetBranchAddress("cuts", cuts);

TH1F* hCuts = new TH1F("hCuts", "Event cuts; ; Events", nCuts, 0, nCuts);
TH1F* hisgoodEvent = new TH1F("hisgoodEvent", "All cuts; ; Events", 2, -0.5, 1.5);
TH1F* hCutRejected = new TH1F("hCutRejected", "Rejected Events; ; Events", nCuts, 0, nCuts);

// ch->SetBranchAddress("trigger",             &trigger);
// ch->SetBranchAddress("vertexClust",         &vertexClust);
// ch->SetBranchAddress("vertexCand",          &vertexCand);
// ch->SetBranchAddress("goodSTART",           &goodSTART);
// ch->SetBranchAddress("noPileUpSTART",       &noPileUpSTART);
// ch->SetBranchAddress("noVETO",              &noVETO);
// ch->SetBranchAddress("goodSTARTVETO",       &goodSTARTVETO);
// ch->SetBranchAddress("goodSTARTMETA",       &goodSTARTMETA);
// ch->SetBranchAddress("isgoodEvent",         &isgoodEvent);


int entry=0;
Bool_t check;
while(entry < ch->GetEntries()) {
    ch->GetEntry(entry);

    check = kTRUE;
    for (Int_t i = 0; i < nCuts; i++){
        if(cuts[i]) {
            hCuts->Fill(i+0.5);
        }
        else {
            hisgoodEvent->Fill(1);
        }

        for (Int_t j = 0; j < nCuts; j++){
            if (i != j) check = check && cuts[j];
            else check = check && !cuts[i];
        }

        if (check) hCutRejected ->Fill(i+0.5);

    }

    hisgoodEvent->Fill(0);
    entry++;
}

string cutName[nCuts] = {"kGoodTRIGGER","kGoodVertexCand","kGoodVertexClast","kGoodSTART",
                            "kNoPileUpSTART","kNoVETO","kGoodSTARTVETO", "kGoodSTARTMETA"};

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
for (Int_t i=0; i < nCuts; i++) { 
    hCuts->GetXaxis()->SetBinLabel(i+1,cutName[i].c_str());
}
hCuts->SetFillColor(38);
hCuts->SetBarWidth(0.9);
hCuts->SetStats(0);
hCuts->Draw("b");
sprintf(picName, "./pics/Cuts.png");
canv->SaveAs(picName);
sprintf(picName, "./pics/Cuts.C");
canv->SaveAs(picName);
delete canv;
delete leg;

string evtName[2] = {"allEvents", "goodEvents"}

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
for (Int_t i=0; i < 2; i++) { 
    hisgoodEvent->GetXaxis()->SetBinLabel(i+1,evtName[i].c_str());
}
hisgoodEvent->SetFillColor(38);
hisgoodEvent->SetBarWidth(0.9);
hisgoodEvent->SetStats(0);
hisgoodEvent->Draw("b");
hisgoodEvent->Draw("b");
sprintf(picName, "./pics/Evt.png");
canv->SaveAs(picName);
sprintf(picName, "./pics/Evt.C");
canv->SaveAs(picName);
delete canv;
delete leg;

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
for (Int_t i=0; i < nCuts; i++) { 
    hCutRejected->GetXaxis()->SetBinLabel(i+1,cutName[i].c_str());
}
hCutRejected->SetFillColor(38);
hCutRejected->SetBarWidth(0.9);
hCutRejected->SetStats(0);
hCutRejected->Draw("b");
sprintf(picName, "./pics/Cuts_rej.png");
canv->SaveAs(picName);
sprintf(picName, "./pics/Cuts_rej.C");
canv->SaveAs(picName);
delete canv;
delete leg;



}


