#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TColor.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>

void drawHistos(char* input="/lustre/nyx/hades/user/tmamont/treeMaker/output/Nov_01_10_56", char* outputdir="/lustre/nyx/hades/user/tmamont/treeMaker/output/Nov_01_10_56"){

	TH2F* hPtVsPcorr = new TH2F("hPtVsPcorr", "#delta p/p_T Vs p_T; #delta p/p_T; p_T [MeV/c]", 100, 0, 0.5, 50, 0, 2100);
	TH1F* hMass1 = new TH1F("hMass1", "Square of mass for 0 < p_T < 200[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass2 = new TH1F("hMass2", "Square of mass for 200 < p_T < 400[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass3 = new TH1F("hMass3", "Square of mass for 400 < p_T < 600[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass4 = new TH1F("hMass4", "Square of mass for 600 < p_T < 800[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass5 = new TH1F("hMass5", "Square of mass for 800 < p_T < 1000[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass6 = new TH1F("hMass6", "Square of mass for 1000 < p_T < 1200[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass7 = new TH1F("hMass7", "Square of mass for 1200 < p_T < 1400[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass8 = new TH1F("hMass8", "Square of mass for 1400 < p_T < 1600[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass9 = new TH1F("hMass9", "Square of mass for 1600 < p_T < 1800[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	TH1F* hMass10 = new TH1F("hMass10", "Square of mass for 1800 < p_T < 2000[MeV/c]; m^2 [Mev^2/c^4]; nTracks", 100, 500, 2000);
	long n = 50000000;
	TCanvas* canv;
	TLegend* leg;
	TChain *ch = new TChain;
	char picName[200];
	char trees[200];
	sprintf(trees, "%s/*.root/tree", input);
	ch->Add(trees);


 	ch->Draw("(pt_corr-pt):pt>>hPtVsPcorr", "", "colz", n);
    ch->Draw("mass*mass>>hMass1", " pt < 200", "", n);
    ch->Draw("mass*mass>>hMass2", "pt > 200 && pt < 400", "", n);
    ch->Draw("mass*mass>>hMass3", "pt > 400 && pt < 600", "", n);
    ch->Draw("mass*mass>>hMass4", "pt > 600 && pt < 800", "", n);
    ch->Draw("mass*mass>>hMass5", "pt > 800 && pt < 1000", "", n);
    ch->Draw("mass*mass>>hMass6", "pt > 1000 && pt < 1200", "", n);
    ch->Draw("mass*mass>>hMass7", "pt > 1200 && pt < 1400", "", n);
    ch->Draw("mass*mass>>hMass8", "pt > 1400 && pt < 1600", "", n);
    ch->Draw("mass*mass>>hMass9", "pt > 1600 && pt < 1800", "", n);
    ch->Draw("mass*mass>>hMass10", "pt > 1800 && pt < 2000", "", n);

    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hPtVsPcorr->Draw("colz");
    hPtVsPcorr->SetStats(false);
    sprintf(picName, "%s/pics/PtVsPcorr.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/PtVsPcorr.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass1->Draw();
    hMass1->SetLineColor(kGreen);
    hMass1->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass1.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass1.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass2->Draw();
    hMass2->SetLineColor(kGreen);
    hMass2->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass2.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass2.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass3->Draw();
    hMass3->SetLineColor(kGreen);
    hMass3->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass3.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass3.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass4->Draw();
    hMass4->SetLineColor(kGreen);
    hMass4->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass4.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass4.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass5->Draw();
    hMass5->SetLineColor(kGreen);
    hMass5->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass5.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass5.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass6->Draw();
    hMass6->SetLineColor(kGreen);
    hMass6->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass6.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass6.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass7->Draw();
    hMass7->SetLineColor(kGreen);
    hMass7->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass7.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass7.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass8->Draw();
    hMass8->SetLineColor(kGreen);
    hMass8->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass8.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass8.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass9->Draw();
    hMass9->SetLineColor(kGreen);
    hMass9->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass9.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass9.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    hMass10->Draw();
    hMass10->SetLineColor(kGreen);
    hMass10->SetMarkerColor(kGreen);
    sprintf(picName, "%s/pics/Mass10.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/Mass10.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg;   
 
}
