{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 23 19:45:06 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-1,441492.9,9,594728);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *hCuts = new TH1F("hCuts","Event cuts",8,0,8);
   hCuts->SetBinContent(1,519426);
   hCuts->SetBinContent(2,565545);
   hCuts->SetBinContent(3,561965);
   hCuts->SetBinContent(4,573567);
   hCuts->SetBinContent(5,565609);
   hCuts->SetBinContent(6,484219);
   hCuts->SetBinContent(7,506254);
   hCuts->SetBinContent(8,462376);
   hCuts->SetBarWidth(0.9);
   hCuts->SetEntries(4238961);
   hCuts->SetStats(0);
   hCuts->SetFillColor(38);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hCuts->SetLineColor(ci);
   hCuts->GetXaxis()->SetTitle(" ");
   hCuts->GetXaxis()->SetBinLabel(1,"kGoodTRIGGER");
   hCuts->GetXaxis()->SetBinLabel(2,"kGoodVertexCand");
   hCuts->GetXaxis()->SetBinLabel(3,"kGoodVertexClast");
   hCuts->GetXaxis()->SetBinLabel(4,"kGoodSTART");
   hCuts->GetXaxis()->SetBinLabel(5,"kNoPileUpSTART");
   hCuts->GetXaxis()->SetBinLabel(6,"kNoVETO");
   hCuts->GetXaxis()->SetBinLabel(7,"kGoodSTARTVETO");
   hCuts->GetXaxis()->SetBinLabel(8,"kGoodSTARTMETA");
   hCuts->GetXaxis()->SetLabelFont(42);
   hCuts->GetXaxis()->SetLabelSize(0.035);
   hCuts->GetXaxis()->SetTitleSize(0.035);
   hCuts->GetXaxis()->SetTitleFont(42);
   hCuts->GetYaxis()->SetTitle(" Events");
   hCuts->GetYaxis()->SetLabelFont(42);
   hCuts->GetYaxis()->SetLabelSize(0.035);
   hCuts->GetYaxis()->SetTitleSize(0.035);
   hCuts->GetYaxis()->SetTitleFont(42);
   hCuts->GetZaxis()->SetLabelFont(42);
   hCuts->GetZaxis()->SetLabelSize(0.035);
   hCuts->GetZaxis()->SetTitleSize(0.035);
   hCuts->GetZaxis()->SetTitleFont(42);
   hCuts->Draw("b");
   
   TPaveText *pt = new TPaveText(0.4030747,0.94,0.5969253,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("Event cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
