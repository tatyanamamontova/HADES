{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Dec  1 14:35:27 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-62.5,-18.75,562.5,168.75);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2F *hFWchargeRPCCut = new TH2F("hFWchargeRPCCut","FW charge vs RPC hits with cuts",500,0,500,150,0,150);
   hFWchargeRPCCut->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFWchargeRPCCut->SetLineColor(ci);
   hFWchargeRPCCut->GetXaxis()->SetTitle(" FW charge");
   hFWchargeRPCCut->GetXaxis()->SetLabelFont(42);
   hFWchargeRPCCut->GetXaxis()->SetLabelSize(0.035);
   hFWchargeRPCCut->GetXaxis()->SetTitleSize(0.035);
   hFWchargeRPCCut->GetXaxis()->SetTitleFont(42);
   hFWchargeRPCCut->GetYaxis()->SetTitle(" RPC hits");
   hFWchargeRPCCut->GetYaxis()->SetLabelFont(42);
   hFWchargeRPCCut->GetYaxis()->SetLabelSize(0.035);
   hFWchargeRPCCut->GetYaxis()->SetTitleSize(0.035);
   hFWchargeRPCCut->GetYaxis()->SetTitleFont(42);
   hFWchargeRPCCut->GetZaxis()->SetTitle(" nEntries");
   hFWchargeRPCCut->GetZaxis()->SetLabelFont(42);
   hFWchargeRPCCut->GetZaxis()->SetLabelSize(0.035);
   hFWchargeRPCCut->GetZaxis()->SetTitleSize(0.035);
   hFWchargeRPCCut->GetZaxis()->SetTitleFont(42);
   hFWchargeRPCCut->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2220402,0.9339831,0.7779598,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("FW charge vs RPC hits with cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
