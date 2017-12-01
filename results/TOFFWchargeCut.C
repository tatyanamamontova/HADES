{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:26 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-12.5,-62.5,112.5,562.5);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hTOFFWchargeCut = new TH2F("hTOFFWchargeCut","TOF hits vs FW charge with cuts",100,0,100,500,0,500);
   hTOFFWchargeCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hTOFFWchargeCut->SetLineColor(ci);
   hTOFFWchargeCut->GetXaxis()->SetTitle(" TOF hits");
   hTOFFWchargeCut->GetXaxis()->SetLabelFont(42);
   hTOFFWchargeCut->GetXaxis()->SetLabelSize(0.035);
   hTOFFWchargeCut->GetXaxis()->SetTitleSize(0.035);
   hTOFFWchargeCut->GetXaxis()->SetTitleFont(42);
   hTOFFWchargeCut->GetYaxis()->SetTitle(" FW charge");
   hTOFFWchargeCut->GetYaxis()->SetLabelFont(42);
   hTOFFWchargeCut->GetYaxis()->SetLabelSize(0.035);
   hTOFFWchargeCut->GetYaxis()->SetTitleSize(0.035);
   hTOFFWchargeCut->GetYaxis()->SetTitleFont(42);
   hTOFFWchargeCut->GetZaxis()->SetTitle(" nEntries");
   hTOFFWchargeCut->GetZaxis()->SetLabelFont(42);
   hTOFFWchargeCut->GetZaxis()->SetLabelSize(0.035);
   hTOFFWchargeCut->GetZaxis()->SetTitleSize(0.035);
   hTOFFWchargeCut->GetZaxis()->SetTitleFont(42);
   hTOFFWchargeCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2241954,0.9339831,0.7758046,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("TOF hits vs FW charge with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
