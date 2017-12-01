{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:27 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-15,-18.75,135,168.75);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hMDCRPCCut = new TH2F("hMDCRPCCut","MDC hits vs RPC hits with cuts",120,0,120,150,0,150);
   hMDCRPCCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hMDCRPCCut->SetLineColor(ci);
   hMDCRPCCut->GetXaxis()->SetTitle(" MDC hits");
   hMDCRPCCut->GetXaxis()->SetLabelFont(42);
   hMDCRPCCut->GetXaxis()->SetLabelSize(0.035);
   hMDCRPCCut->GetXaxis()->SetTitleSize(0.035);
   hMDCRPCCut->GetXaxis()->SetTitleFont(42);
   hMDCRPCCut->GetYaxis()->SetTitle(" RPC hits");
   hMDCRPCCut->GetYaxis()->SetLabelFont(42);
   hMDCRPCCut->GetYaxis()->SetLabelSize(0.035);
   hMDCRPCCut->GetYaxis()->SetTitleSize(0.035);
   hMDCRPCCut->GetYaxis()->SetTitleFont(42);
   hMDCRPCCut->GetZaxis()->SetTitle(" nEntries");
   hMDCRPCCut->GetZaxis()->SetLabelFont(42);
   hMDCRPCCut->GetZaxis()->SetLabelSize(0.035);
   hMDCRPCCut->GetZaxis()->SetTitleSize(0.035);
   hMDCRPCCut->GetZaxis()->SetTitleFont(42);
   hMDCRPCCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2356897,0.94,0.7643103,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("MDC hits vs RPC hits with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
