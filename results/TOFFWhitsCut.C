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
   
   TH2F *hTOFFWhitsCut = new TH2F("hTOFFWhitsCut","TOF hits vs FW Hits with cuts",100,0,100,120,0,120);
   hTOFFWhitsCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hTOFFWhitsCut->SetLineColor(ci);
   hTOFFWhitsCut->GetXaxis()->SetTitle(" TOF Hits");
   hTOFFWhitsCut->GetXaxis()->SetLabelFont(42);
   hTOFFWhitsCut->GetXaxis()->SetLabelSize(0.035);
   hTOFFWhitsCut->GetXaxis()->SetTitleSize(0.035);
   hTOFFWhitsCut->GetXaxis()->SetTitleFont(42);
   hTOFFWhitsCut->GetYaxis()->SetTitle(" FW hits");
   hTOFFWhitsCut->GetYaxis()->SetLabelFont(42);
   hTOFFWhitsCut->GetYaxis()->SetLabelSize(0.035);
   hTOFFWhitsCut->GetYaxis()->SetTitleSize(0.035);
   hTOFFWhitsCut->GetYaxis()->SetTitleFont(42);
   hTOFFWhitsCut->GetZaxis()->SetTitle(" nEntries");
   hTOFFWhitsCut->GetZaxis()->SetLabelFont(42);
   hTOFFWhitsCut->GetZaxis()->SetLabelSize(0.035);
   hTOFFWhitsCut->GetZaxis()->SetTitleSize(0.035);
   hTOFFWhitsCut->GetZaxis()->SetTitleFont(42);
   hTOFFWhitsCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2479023,0.94,0.7520977,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("TOF hits vs FW Hits with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
