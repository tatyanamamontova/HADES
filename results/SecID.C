{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Nov 27 14:53:27 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-1.25,2744492,6.25,3340068);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *hSecId = new TH1F("hSecId","Sector information from MDC",6,-0.5,5.5);
   hSecId->SetBinContent(1,3091429);
   hSecId->SetBinContent(2,3082206);
   hSecId->SetBinContent(3,3257822);
   hSecId->SetBinContent(4,2952361);
   hSecId->SetBinContent(5,2825658);
   hSecId->SetBinContent(6,3254779);
   hSecId->SetEntries(1.846426e+07);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("hSecId");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries =   1.846426e+07");
   text = ptstats->AddText("Mean  =  2.493");
   text = ptstats->AddText("RMS   =  1.718");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hSecId->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hSecId);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hSecId->SetLineColor(ci);
   hSecId->GetXaxis()->SetTitle(" nSector");
   hSecId->GetXaxis()->SetLabelFont(42);
   hSecId->GetXaxis()->SetLabelSize(0.035);
   hSecId->GetXaxis()->SetTitleSize(0.035);
   hSecId->GetXaxis()->SetTitleFont(42);
   hSecId->GetYaxis()->SetTitle(" nTracks");
   hSecId->GetYaxis()->SetLabelFont(42);
   hSecId->GetYaxis()->SetLabelSize(0.035);
   hSecId->GetYaxis()->SetTitleSize(0.035);
   hSecId->GetYaxis()->SetTitleFont(42);
   hSecId->GetZaxis()->SetLabelFont(42);
   hSecId->GetZaxis()->SetLabelSize(0.035);
   hSecId->GetZaxis()->SetTitleSize(0.035);
   hSecId->GetZaxis()->SetTitleFont(42);
   hSecId->Draw("");
   
   TPaveText *pt = new TPaveText(0.2500575,0.94,0.7499425,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Sector information from MDC");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
