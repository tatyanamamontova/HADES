//@brief Scripts for drawing trig variables
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
#include "TCanvas.h"
#include "TLegend.h"

void drawHistoForTrigger(char* input) {

TChain *ch = new TChain;
char picName[200];
char trees[200];
sprintf(trees, "%s.root/tree", input);
ch->Add(trees);

const Short_t nTriggers = 8;
Bool_t trigInd[nTriggers];

ch->SetBranchAddress("trigInd", trigInd);

TH1F* hTrig = new TH1F("hCuts", "Event cuts; ; Events", nTriggers, 0, nTriggers);


int entry=0;
while(entry < ch->GetEntries()) {
    ch->GetEntry(entry);

    for (Int_t i = 0; i < nTriggers; i++){
        if(trigInd[i]) hTrig->Fill(i+0.5);     
    }
    
    entry++;
}

string cutName[nTriggers] = {"PT1","PT2","PT3","PT4"};

canv = new TCanvas();
leg = new TLegend(0.7,0.7,0.9,0.9);
for (Int_t i=0; i < nTriggers; i++) { 
    hTrig->GetXaxis()->SetBinLabel(i+1,cutName[i].c_str());
}
hTrig->SetFillColor(38);
hTrig->SetBarWidth(0.9);
hTrig->SetStats(0);
hTrig->Draw("b");
sprintf(picName, "./pics/Triggers_%s.png", input);
canv->SaveAs(picName);
sprintf(picName, "./pics/Triggers_%s.C", input);
canv->SaveAs(picName);
delete canv;
delete leg;



}


