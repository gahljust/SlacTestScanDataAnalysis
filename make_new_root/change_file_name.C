

void change_file_name(int runner){

TString path = "/Users/justingahley/apps/root/example/make_new_root/root_analyzed_files/";

TString path2 = "/Users/justingahley/apps/root/example/make_new_root/root_update_analyzed_files/";

TFile *oldfile = TFile::Open(path + Form("run_%d_analyzed.root",runner));

TTree *oldtree = (TTree*)oldfile->Get("Rec");


/* /name for tree
TString treename;
treename.Form("R%d",runner);*/

//Create a new file + a clone of old tree in new file
TFile *newfile = new TFile(path2 + Form("run_%d_update_analyzed.root",runner),"recreate");
TTree *newtree = oldtree->CloneTree();


newtree->SetName(Form("R%d",runner));

newtree->Print();
newfile->Write();

delete oldfile;
delete newfile;

}
