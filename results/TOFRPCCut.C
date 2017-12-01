{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:26 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-12.5,-18.75,112.5,168.75);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hTOFRPCCut = new TH2F("hTOFRPCCut","TOF hits vs RPC hits with cuts",100,0,100,150,0,150);
   hTOFRPCCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hTOFRPCCut->SetLineColor(ci);
   hTOFRPCCut->GetXaxis()->SetTitle(" TOF hits");
   hTOFRPCCut->GetXaxis()->SetLabelFont(42);
   hTOFRPCCut->GetXaxis()->SetLabelSize(0.035);
   hTOFRPCCut->GetXaxis()->SetTitleSize(0.035);
   hTOFRPCCut->GetXaxis()->SetTitleFont(42);
   hTOFRPCCut->GetYaxis()->SetTitle(" RPC hits");
   hTOFRPCCut->GetYaxis()->SetLabelFont(42);
   hTOFRPCCut->GetYaxis()->SetLabelSize(0.035);
   hTOFRPCCut->GetYaxis()->SetTitleSize(0.035);
   hTOFRPCCut->GetYaxis()->SetTitleFont(42);
   hTOFRPCCut->GetZaxis()->SetTitle(" nEntries");
   hTOFRPCCut->GetZaxis()->SetLabelFont(42);
   hTOFRPCCut->GetZaxis()->SetLabelSize(0.035);
   hTOFRPCCut->GetZaxis()->SetTitleSize(0.035);
   hTOFRPCCut->GetZaxis()->SetTitleFont(42);
   hTOFRPCCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.24,0.94,0.76,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("TOF hits vs RPC hits with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
