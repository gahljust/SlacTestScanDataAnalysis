#include "read_DB.h"

void DBinput2_to_root(int runner = 239) {

  TString path = "/Users/justingahley/apps/root/example/make_new_root/root_analyzed_files/";

  //open file
  TFile *f = TFile::Open(path + Form("run_%d_analyzed.root",runner),"UPDATE");

  // make pointer for the tree
  TTree *tree = (TTree*)f->Get("Rec");

  //assign variables from csv
  Int_t runNum = run_num(runner);
  Int_t voltage = HV(runner);
  Int_t Nevents = events(runner);
  Int_t Config = config(runner);
  Int_t gEvents = goldEvents(runner);
  Float_t energy = EBeam(runner);
  Float_t xpos = xPos(runner);
  Float_t ypos = yPos(runner);
  Float_t deltx = delta_x(runner);
  Float_t delty = delta_y(runner);

  // create branches for new varibles
  TBranch *b1 = tree->Branch("Run",&runNum,"run_num/I");
  TBranch *b2 = tree->Branch("Voltage",&voltage,"voltage/I");
  TBranch *b3 = tree->Branch("Config",&Config,"Config/I");
  TBranch *b4 = tree->Branch("Energy",&energy,"energy/F");
  TBranch *b5 = tree->Branch("X_Position",&xpos,"xpos/F");
  TBranch *b6 = tree->Branch("Y_Position",&ypos,"ypos/F");
  TBranch *b7 = tree->Branch("Delta_X",&deltx,"deltx/F");
  TBranch *b8 = tree->Branch("Delta_Y",&delty,"delty/F");
  TBranch *b9 = tree->Branch("Events",&Nevents,"Nevents/I");
  TBranch *b10 = tree->Branch("goldEvents",&gEvents,"gEvents/I");


  // get the number of events in root file
  Int_t nentries = (Int_t)tree->GetEntries();

  //fill the branches with new events
  for (Int_t i = 0; i < nentries; i++) {
    runNum;
    b1->Fill();
    voltage;
    b2->Fill();
    Config;
    b3->Fill();
    energy;
    b4->Fill();
    xpos;
    b5->Fill();
    ypos;
    b6->Fill();
    deltx;
    b7->Fill();
    delty;
    b8->Fill();
    Nevents;
    b9->Fill();
    gEvents;
    b10->Fill();
}

  // write to the new tree and erase the old tree
  tree->Write("",TObject::kOverwrite);
  tree->Print();


  //check all is good
  /*printf("%d\n",runNum);
  printf("%d\n",voltage);
  printf("%d\n",Config);
  printf("%f\n",energy);
  printf("%f\n",xpos);
  printf("%f\n",ypos);
  printf("%f\n",deltx);
  printf("%f\n",delty);
  printf("%d\n",Nevents);
  printf("%d\n",gEvents);*/
}
