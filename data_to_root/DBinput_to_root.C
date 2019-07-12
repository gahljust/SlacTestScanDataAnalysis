#include <stdio.h>


{
// example of macro to read data from an ascii file and // create a root file with an histogram and a TTree gROOT->Reset();
// the structure to hold the variables for the branch
struct run_t
{
   Int_t run_num;
   Int_t HV;
   Int_t config;
   Int_t E_beam;
   Int_t x_pos;
   Int_t y_pos;
   Int_t delta_x;
   Int_t delta_y;
   Int_t events;
   Int_t goldEvents;
    };
run_t run;
// continued...
// open the ASCII file
FILE *fp = fopen("DBinput.dat","r");
char line[81];
// create a new ROOT file
TFile *f = new TFile("DBinputFile.root","RECREATE");
// create a TTree
TTree *tree = new TTree("T","staff data from ascii file");
// create one branch with all information from the stucture
tree->Branch("values",&run.run_num,"run_num/I:HV:config:E_beam:x_pos:y_pos:delta_x:delta_y:events:goldEvents"); // fill the tree from the values in ASCII file
while (fgets(line,80,fp))
{ sscanf(&line[0],"%d%d%d%d%d%d%d%d%d%d",&run.run_num,&run.HV,
       &run.config,&run.E_beam,&run.x_pos,&run.y_pos);
  sscanf(&line[48],"%d%d%d%d",&run.delta_x,&run.delta_y,&run.events,&run.goldEvents);
/*sscanf(&line[24],"%d%d",&run.events,&run.goldEvents);*/
   tree->Fill();
}
   // check what the tree looks like
   tree->Print();
   fclose(fp);
   f->Write();
}
