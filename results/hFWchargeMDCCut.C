{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:27 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-62.5,-15,562.5,135);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hFWchargeMDCCut = new TH2F("hFWchargeMDCCut","FW charge vs MDC tracks with cuts",500,0,500,120,0,120);
   hFWchargeMDCCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFWchargeMDCCut->SetLineColor(ci);
   hFWchargeMDCCut->GetXaxis()->SetTitle(" FW charge");
   hFWchargeMDCCut->GetXaxis()->SetLabelFont(42);
   hFWchargeMDCCut->GetXaxis()->SetLabelSize(0.035);
   hFWchargeMDCCut->GetXaxis()->SetTitleSize(0.035);
   hFWchargeMDCCut->GetXaxis()->SetTitleFont(42);
   hFWchargeMDCCut->GetYaxis()->SetTitle(" MDC tracks");
   hFWchargeMDCCut->GetYaxis()->SetLabelFont(42);
   hFWchargeMDCCut->GetYaxis()->SetLabelSize(0.035);
   hFWchargeMDCCut->GetYaxis()->SetTitleSize(0.035);
   hFWchargeMDCCut->GetYaxis()->SetTitleFont(42);
   hFWchargeMDCCut->GetZaxis()->SetTitle(" nEntries");
   hFWchargeMDCCut->GetZaxis()->SetLabelFont(42);
   hFWchargeMDCCut->GetZaxis()->SetLabelSize(0.035);
   hFWchargeMDCCut->GetZaxis()->SetTitleSize(0.035);
   hFWchargeMDCCut->GetZaxis()->SetTitleFont(42);
   hFWchargeMDCCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.1990517,0.9339831,0.8009483,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("FW charge vs MDC tracks with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
