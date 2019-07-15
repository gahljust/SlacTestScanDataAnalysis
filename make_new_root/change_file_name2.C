

void change_file_name2(){


TFile *oldfile = TFile::Open("/Users/justingahley/Big.root");

TTree *oldtree = (TTree*)oldfile->Get("Allruns");


/* /name for tree
TString treename;
treename.Form("R%d",runner);*/

//Create a new file + a clone of old tree in new file
TFile *newfile = new TFile("NewBig.root","recreate");
TTree *newtree = oldtree->CloneTree();

newfile->Write();
newtree->Print();

delete oldfile;
delete newfile;

}
