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
   
   TH2F *hFWhitsRPCCut = new TH2F("hFWhitsRPCCut","FW hits vs RPC hits with cuts",120,0,120,150,0,150);
   hFWhitsRPCCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFWhitsRPCCut->SetLineColor(ci);
   hFWhitsRPCCut->GetXaxis()->SetTitle(" FW hits");
   hFWhitsRPCCut->GetXaxis()->SetLabelFont(42);
   hFWhitsRPCCut->GetXaxis()->SetLabelSize(0.035);
   hFWhitsRPCCut->GetXaxis()->SetTitleSize(0.035);
   hFWhitsRPCCut->GetXaxis()->SetTitleFont(42);
   hFWhitsRPCCut->GetYaxis()->SetTitle(" RPC hits");
   hFWhitsRPCCut->GetYaxis()->SetLabelFont(42);
   hFWhitsRPCCut->GetYaxis()->SetLabelSize(0.035);
   hFWhitsRPCCut->GetYaxis()->SetTitleSize(0.035);
   hFWhitsRPCCut->GetYaxis()->SetTitleFont(42);
   hFWhitsRPCCut->GetZaxis()->SetTitle(" nEntries");
   hFWhitsRPCCut->GetZaxis()->SetLabelFont(42);
   hFWhitsRPCCut->GetZaxis()->SetLabelSize(0.035);
   hFWhitsRPCCut->GetZaxis()->SetTitleSize(0.035);
   hFWhitsRPCCut->GetZaxis()->SetTitleFont(42);
   hFWhitsRPCCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2479023,0.94,0.7520977,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("FW hits vs RPC hits with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
