/// macro_code
///
/// \author Sebastian Sarasti Zambonino - 2022
#include "Riostream.h"
#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include <vector>

void det_reader1() {
   // Create a histogram for the values we read.
   auto myHist1 = new TH1F("h1","ntuple",300,0,2);
   auto myHist2 = new TH1F("h2","ntuple",300,0,2);
   auto myHist3 = new TH1F("h3","ntuple",300,0,2);
   auto myHist4 = new TH1F("h4","ntuple",300,0,2);


   // Load the file which contains the trees.
   auto myFile = TFile::Open("output0.root");
   if (!myFile || myFile->IsZombie()) {
      return;
   }
   // call interested trees
   TTreeReader myReader1("Detector_1", myFile);
   TTreeReader myReader2("Detector_2", myFile);
   TTreeReader myReader3("Detector_3", myFile);
   TTreeReader myReader4("Detector_4", myFile);
   // call the branch needed
   TTreeReaderValue<Double_t> mDet1(myReader1, "fedep1");
   TTreeReaderValue<Double_t> mDet2(myReader2, "fedep2");
   TTreeReaderValue<Double_t> mDet3(myReader3, "fedep3");
   TTreeReaderValue<Double_t> mDet4(myReader4, "fedep4");
   // create a file to save the results
   ofstream out;
   out.open("NaIDetector_matrix.dat");
   // add loaded trees into histograms
   while (myReader1.Next()) {
     // fill histograms with data
     myHist1->Fill(*mDet1);
   }
   while (myReader2.Next()) {
     // fill histograms with data
     myHist2->Fill(*mDet2);
   }
   
   while (myReader3.Next()) {
     // fill histograms with data
     myHist3->Fill(*mDet3);
   }
   while (myReader4.Next()) {
     // fill histograms with data
     myHist4->Fill(*mDet4);
   }
   // get the number of the bins
   int nbins= myHist1->GetXaxis()->GetNbins();
   // iterate to save each bin and the value
   for (int bin=1; bin<=nbins; bin++){
      // to print the results
      // printf("%4d %6.1f %4.11f %4.11f\n",bin, myHist1->GetXaxis()->GetBinCenter(bin), myHist1->GetBinContent(bin), myHist2->GetBinContent(bin)); 
      // to save the results in a matrix
      out<< myHist1->GetXaxis()->GetBinCenter(bin)<<" "<<myHist1->GetBinContent(bin)<<" "<<myHist2->GetBinContent(bin) << " "<<myHist3->GetBinContent(bin)<<" "<<myHist4->GetBinContent(bin) << endl;

   }
   // This lines draw the results
   //myHist1->Draw();
   //myHist2->Draw();
   out.close();
}
