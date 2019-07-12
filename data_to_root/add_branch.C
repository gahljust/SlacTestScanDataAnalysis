void add_branch(int run) {
    TFile f("run_%d_analyzed.root", "update", run);
    Float_t new_v;
    TTree *Rec = (TTree*)f.Get("Rec");
    TBranch *newBranch = tree1->Branch("new_v", &new_v, "new_v/F");
    for (int_t i = 0; i < 10; i++){


    }



    /*Long64_t nentries = tree1->GetEntries(); // read the number of entries in the t3
    for (Long64_t i = 0; i < nentries; i++) {
        new_v= gRandom->Gaus(0, 1);
        newBranch->Fill();
    }*/
    tree1->Write("", TObject::kOverwrite); // save only the new version of the tree
}
