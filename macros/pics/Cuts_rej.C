{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 23 19:45:06 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-1,-8112.957,9,73016.61);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *hCutRejected = new TH1F("hCutRejected","Rejected Events",8,0,8);
   hCutRejected->SetBinContent(1,20165);
   hCutRejected->SetBinContent(2,383);
   hCutRejected->SetBinContent(3,287);
   hCutRejected->SetBinContent(4,1655);
   hCutRejected->SetBinContent(5,7633);
   hCutRejected->SetBinContent(6,22361);
   hCutRejected->SetBinContent(7,13472);
   hCutRejected->SetBinContent(8,61813);
   hCutRejected->SetBarWidth(0.9);
   hCutRejected->SetEntries(127769);
   hCutRejected->SetStats(0);
   hCutRejected->SetFillColor(38);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hCutRejected->SetLineColor(ci);
   hCutRejected->GetXaxis()->SetTitle(" ");
   hCutRejected->GetXaxis()->SetBinLabel(1,"kGoodTRIGGER");
   hCutRejected->GetXaxis()->SetBinLabel(2,"kGoodVertexCand");
   hCutRejected->GetXaxis()->SetBinLabel(3,"kGoodVertexClast");
   hCutRejected->GetXaxis()->SetBinLabel(4,"kGoodSTART");
   hCutRejected->GetXaxis()->SetBinLabel(5,"kNoPileUpSTART");
   hCutRejected->GetXaxis()->SetBinLabel(6,"kNoVETO");
   hCutRejected->GetXaxis()->SetBinLabel(7,"kGoodSTARTVETO");
   hCutRejected->GetXaxis()->SetBinLabel(8,"kGoodSTARTMETA");
   hCutRejected->GetXaxis()->SetLabelFont(42);
   hCutRejected->GetXaxis()->SetLabelSize(0.035);
   hCutRejected->GetXaxis()->SetTitleSize(0.035);
   hCutRejected->GetXaxis()->SetTitleFont(42);
   hCutRejected->GetYaxis()->SetTitle(" Events");
   hCutRejected->GetYaxis()->SetLabelFont(42);
   hCutRejected->GetYaxis()->SetLabelSize(0.035);
   hCutRejected->GetYaxis()->SetTitleSize(0.035);
   hCutRejected->GetYaxis()->SetTitleFont(42);
   hCutRejected->GetZaxis()->SetLabelFont(42);
   hCutRejected->GetZaxis()->SetLabelSize(0.035);
   hCutRejected->GetZaxis()->SetTitleSize(0.035);
   hCutRejected->GetZaxis()->SetTitleFont(42);
   hCutRejected->Draw("b");
   
   TPaveText *pt = new TPaveText(0.3570977,0.9339831,0.6429023,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Rejected Events");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
