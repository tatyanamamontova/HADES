{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Nov 27 12:52:31 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-500,-0.13125,4500,1.18125);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *hMassRPC = new TH1F("hMassRPC","Mass for RPC",4000,0,4000);
   hMassRPC->SetStats(0);
   hMassRPC->SetLineColor(2);
   hMassRPC->GetXaxis()->SetTitle(" mass [MeV/c^2]");
   hMassRPC->GetXaxis()->SetLabelFont(42);
   hMassRPC->GetXaxis()->SetLabelSize(0.035);
   hMassRPC->GetXaxis()->SetTitleSize(0.035);
   hMassRPC->GetXaxis()->SetTitleFont(42);
   hMassRPC->GetYaxis()->SetTitle(" nTracks");
   hMassRPC->GetYaxis()->SetLabelFont(42);
   hMassRPC->GetYaxis()->SetLabelSize(0.035);
   hMassRPC->GetYaxis()->SetTitleSize(0.035);
   hMassRPC->GetYaxis()->SetTitleFont(42);
   hMassRPC->GetZaxis()->SetLabelFont(42);
   hMassRPC->GetZaxis()->SetLabelSize(0.035);
   hMassRPC->GetZaxis()->SetTitleSize(0.035);
   hMassRPC->GetZaxis()->SetTitleFont(42);
   hMassRPC->Draw("");
   
   TH1F *hMassTOF = new TH1F("hMassTOF","Mass for TOF",4000,0,4000);
   hMassTOF->SetStats(0);
   hMassTOF->SetLineColor(3);
   hMassTOF->GetXaxis()->SetTitle(" mass [MeV/c^2]");
   hMassTOF->GetXaxis()->SetLabelFont(42);
   hMassTOF->GetXaxis()->SetLabelSize(0.035);
   hMassTOF->GetXaxis()->SetTitleSize(0.035);
   hMassTOF->GetXaxis()->SetTitleFont(42);
   hMassTOF->GetYaxis()->SetTitle(" nTracks");
   hMassTOF->GetYaxis()->SetLabelFont(42);
   hMassTOF->GetYaxis()->SetLabelSize(0.035);
   hMassTOF->GetYaxis()->SetTitleSize(0.035);
   hMassTOF->GetYaxis()->SetTitleFont(42);
   hMassTOF->GetZaxis()->SetLabelFont(42);
   hMassTOF->GetZaxis()->SetLabelSize(0.035);
   hMassTOF->GetZaxis()->SetTitleSize(0.035);
   hMassTOF->GetZaxis()->SetTitleFont(42);
   hMassTOF->Draw("same");
   
   TLegend *leg = new TLegend(0.7,0.7,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hMassRPC","Meta mass for TOF","lp");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hMassTOF","Meta mass for RPC","lp");
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.377931,0.94,0.622069,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Mass for RPC");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
