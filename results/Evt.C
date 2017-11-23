{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 23 20:15:28 2017) by ROOT version5.34/34
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-0.75,231729.5,1.75,693587.4);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *hisgoodEvent = new TH1F("hisgoodEvent","All cuts",2,-0.5,1.5);
   hisgoodEvent->SetBinContent(1,629807);
   hisgoodEvent->SetBinContent(2,294672);
   hisgoodEvent->SetBarWidth(0.9);
   hisgoodEvent->SetEntries(924479);
   hisgoodEvent->SetStats(0);
   hisgoodEvent->SetFillColor(38);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hisgoodEvent->SetLineColor(ci);
   hisgoodEvent->GetXaxis()->SetTitle(" ");
   hisgoodEvent->GetXaxis()->SetBinLabel(1,"allEvents");
   hisgoodEvent->GetXaxis()->SetBinLabel(2,"goodEvents");
   hisgoodEvent->GetXaxis()->SetLabelFont(42);
   hisgoodEvent->GetXaxis()->SetLabelSize(0.035);
   hisgoodEvent->GetXaxis()->SetTitleSize(0.035);
   hisgoodEvent->GetXaxis()->SetTitleFont(42);
   hisgoodEvent->GetYaxis()->SetTitle(" Events");
   hisgoodEvent->GetYaxis()->SetLabelFont(42);
   hisgoodEvent->GetYaxis()->SetLabelSize(0.035);
   hisgoodEvent->GetYaxis()->SetTitleSize(0.035);
   hisgoodEvent->GetYaxis()->SetTitleFont(42);
   hisgoodEvent->GetZaxis()->SetLabelFont(42);
   hisgoodEvent->GetZaxis()->SetLabelSize(0.035);
   hisgoodEvent->GetZaxis()->SetTitleSize(0.035);
   hisgoodEvent->GetZaxis()->SetTitleFont(42);
   hisgoodEvent->Draw("b");
   
   TPaveText *pt = new TPaveText(0.4282184,0.94,0.5717816,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("All cuts");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
