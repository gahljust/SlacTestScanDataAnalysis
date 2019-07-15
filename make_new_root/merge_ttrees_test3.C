
void merge_ttrees_test3(){

  TFile *input = TFile::Open("/Users/justingahley/Big.root","UPDATE");

  TList *treelist = new TList;


  for (int i = 132; i < 156; i++){
    TTree *oldtree = (TTree*)input->Get(Form("R%d",i));
    treelist->Add(oldtree);
  }

  for (int i = 177; i < 226; i++){
    TTree *oldtree = (TTree*)input->Get(Form("R%d",i));
    treelist->Add(oldtree);
  }


  for (int i = 239; i < 276; i++){
    TTree *oldtree = (TTree*)input->Get(Form("R%d",i));
    treelist->Add(oldtree);
  }

  for (int i = 285; i < 303; i++){
    TTree *oldtree = (TTree*)input->Get(Form("R%d",i));
    treelist->Add(oldtree);
  }

  for (int i = 317; i < 371; i++){
    TTree *oldtree = (TTree*)input->Get(Form("R%d",i));
    treelist->Add(oldtree);
  }

  for (int i = 399; i < 459; i++){
    TTree *oldtree = (TTree*)input->Get(Form("R%d",i));
    treelist->Add(oldtree);
  }


  TTree *AllRuns = TTree::MergeTrees(treelist);
  AllRuns->SetName("Allruns");

  AllRuns->Write("",TObject::kOverwrite);
  AllRuns->Print();

}
