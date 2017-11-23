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

void drawTofHits(char* input) {

TChain *ch = new TChain;
char picName[200];
char trees[200];
sprintf(trees, "%s.root/tree", input);
ch->Add(trees);

const Short_t nTriggers = 4;
Bool_t trigInd[nTriggers];
Int_t nTofHitsCut;

ch->SetBranchAddress("trigInd", trigInd);
ch->SetBranchAddress("nTofHitsCut", &nTofHitsCut);

TH1F* hTOFPT2 = new TH1F("hTof", "Tof Hits with PT; nEvents; nHits", 120, 0, 120);
TH1F* hTOFPT3 = new TH1F("hTof", "Tof Hits with PT; nEvents; nHits", 120, 0, 120);



int entry=0;
int count;
while(entry < ch->GetEntries()) {
    ch->GetEntry(entry);
    count = 0;
    if (trigInd[1]) hTOFPT2->Fill(nTofHitsCut);
	if (trigInd[2]) hTOFPT3->Fill(nTofHitsCut);	 
    entry++;
}


canv = new TCanvas();
hTOFPT2->SetLineColor(2);
hTOFPT3->SetLineColor(3);
<<<<<<< HEAD
hTOFPT3->SetStats(0);
hTOFPT2->SetStats(0);
hTOFPT2->Draw();
hTOFPT3->Draw("same");



leg = new TLegend(0.2,0.15,0.9,0.9);
leg->SetFillColor(0);
leg->SetBorderSize(0);
leg->SetTextSize(0.03);
leg->SetTextFont(42);
leg->AddEntry(hTOFPT2, "PT2", "l");
leg->AddEntry(hTOFPT3, "PT3", "l");
leg->Draw();

=======
leg->AddEntry(hTOFPT2, "PT2", "l");
leg->AddEntry(hTOFPT3, "PT3", "l");
leg->Draw();
hTOFPT2->Draw();
hTOFPT3->Draw("same");
>>>>>>> c0de756f43fe396ebd26314276a263a106940fc4
sprintf(picName, "./pics/TOF.png");
canv->SaveAs(picName);
sprintf(picName, "./pics/TOF.C");
canv->SaveAs(picName);
delete canv;
delete leg;



}


