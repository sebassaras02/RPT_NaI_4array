/// \file
/// \ingroup tutorial_tree
/// \notebook
/// TTreeReader simplest example.
///
/// Read data from hsimple.root (written by hsimple.C)
///
/// \macro_code
///
/// \author Anders Eie, 2013
#include "Riostream.h"
#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void det_reader3() {
   // Create a histogram for the values we read.
   auto myHist = new TH1F("h1","ntuple",300,0,2);

   // Open the file containing the tree.
   auto myFile = TFile::Open("output0.root");
   if (!myFile || myFile->IsZombie()) {
      return;
   }

   TTreeReader myReader("Detector_3", myFile);
   TTreeReaderValue<Double_t> myPx(myReader, "fedep3");
   ofstream out;
   out.open("NaIDetector_D3.dat");
   while (myReader.Next()) {

     myHist->Fill(*myPx);
     printf("Line: %f \n", *myPx);
     out<< *myPx << endl;
   }
   myHist->Draw();
   out.close();
}
