{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:26 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-12.5,-15,112.5,135);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hTOFMDCCut = new TH2F("hTOFMDCCut","TOF hits vs MDC tracks with cuts",100,0,100,120,0,120);
   hTOFMDCCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hTOFMDCCut->SetLineColor(ci);
   hTOFMDCCut->GetXaxis()->SetTitle(" TOF hits");
   hTOFMDCCut->GetXaxis()->SetLabelFont(42);
   hTOFMDCCut->GetXaxis()->SetLabelSize(0.035);
   hTOFMDCCut->GetXaxis()->SetTitleSize(0.035);
   hTOFMDCCut->GetXaxis()->SetTitleFont(42);
   hTOFMDCCut->GetYaxis()->SetTitle(" MDC tracks");
   hTOFMDCCut->GetYaxis()->SetLabelFont(42);
   hTOFMDCCut->GetYaxis()->SetLabelSize(0.035);
   hTOFMDCCut->GetYaxis()->SetTitleSize(0.035);
   hTOFMDCCut->GetYaxis()->SetTitleFont(42);
   hTOFMDCCut->GetZaxis()->SetTitle(" nEntries");
   hTOFMDCCut->GetZaxis()->SetLabelFont(42);
   hTOFMDCCut->GetZaxis()->SetLabelSize(0.035);
   hTOFMDCCut->GetZaxis()->SetTitleSize(0.035);
   hTOFMDCCut->GetZaxis()->SetTitleFont(42);
   hTOFMDCCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2170115,0.94,0.7829885,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("TOF hits vs MDC tracks with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
