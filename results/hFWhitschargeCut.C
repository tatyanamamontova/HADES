{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:26 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-15,-62.5,135,562.5);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hFWhitschargeCut = new TH2F("hFWhitschargeCut","FW hits vs FW charge cuts",120,0,120,500,0,500);
   hFWhitschargeCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFWhitschargeCut->SetLineColor(ci);
   hFWhitschargeCut->GetXaxis()->SetTitle(" FW hits");
   hFWhitschargeCut->GetXaxis()->SetLabelFont(42);
   hFWhitschargeCut->GetXaxis()->SetLabelSize(0.035);
   hFWhitschargeCut->GetXaxis()->SetTitleSize(0.035);
   hFWhitschargeCut->GetXaxis()->SetTitleFont(42);
   hFWhitschargeCut->GetYaxis()->SetTitle(" FW charge");
   hFWhitschargeCut->GetYaxis()->SetLabelFont(42);
   hFWhitschargeCut->GetYaxis()->SetLabelSize(0.035);
   hFWhitschargeCut->GetYaxis()->SetTitleSize(0.035);
   hFWhitschargeCut->GetYaxis()->SetTitleFont(42);
   hFWhitschargeCut->GetZaxis()->SetTitle(" nEntries");
   hFWhitschargeCut->GetZaxis()->SetLabelFont(42);
   hFWhitschargeCut->GetZaxis()->SetLabelSize(0.035);
   hFWhitschargeCut->GetZaxis()->SetTitleSize(0.035);
   hFWhitschargeCut->GetZaxis()->SetTitleFont(42);
   hFWhitschargeCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2708908,0.9339831,0.7291092,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("FW hits vs FW charge cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
