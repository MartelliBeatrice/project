void test(){

  TFile *file= new TFile("file.root", "READ");
  file->cd();
  TH1D *h= (TH1D *) gDirectory->Get("histo");
  h->Draw();

  TF1 *fun = new TF1("fun","gaus(0)",-5.,5.);
  fun->SetParameter(0,h->GetBinContent(h->GetMaximumBin()));//prende contenuto del bin
  fun->SetParameter(1,h->GetBinCenter(h->GetMaximumBin()));//prende il centro del bin
  fun->SetParameter(2,h->GetStdDev()); //parametri per la deviazione standard
  fun->SetParLimits(1,-2.,2.);
  h->Fit(fun, "R");
}
