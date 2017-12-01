{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:26 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-15,-15,135,135);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hFWhitsMDCCut = new TH2F("hFWhitsMDCCut","FW hits vs MDC tracks with cuts",120,0,120,120,0,120);
   hFWhitsMDCCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFWhitsMDCCut->SetLineColor(ci);
   hFWhitsMDCCut->GetXaxis()->SetTitle(" FW hits");
   hFWhitsMDCCut->GetXaxis()->SetLabelFont(42);
   hFWhitsMDCCut->GetXaxis()->SetLabelSize(0.035);
   hFWhitsMDCCut->GetXaxis()->SetTitleSize(0.035);
   hFWhitsMDCCut->GetXaxis()->SetTitleFont(42);
   hFWhitsMDCCut->GetYaxis()->SetTitle(" MDC tracks");
   hFWhitsMDCCut->GetYaxis()->SetLabelFont(42);
   hFWhitsMDCCut->GetYaxis()->SetLabelSize(0.035);
   hFWhitsMDCCut->GetYaxis()->SetTitleSize(0.035);
   hFWhitsMDCCut->GetYaxis()->SetTitleFont(42);
   hFWhitsMDCCut->GetZaxis()->SetTitle(" nEntries");
   hFWhitsMDCCut->GetZaxis()->SetLabelFont(42);
   hFWhitsMDCCut->GetZaxis()->SetLabelSize(0.035);
   hFWhitsMDCCut->GetZaxis()->SetTitleSize(0.035);
   hFWhitsMDCCut->GetZaxis()->SetTitleFont(42);
   hFWhitsMDCCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2249138,0.94,0.7750862,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("FW hits vs MDC tracks with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
