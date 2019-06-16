
/* This file creats a graph for the angle scan of the tandem detector
Makes a canvas Then makes three graphs with for loops that run through the runs
feed in. It grabs PE values from the read_csv.h, and needs hard coded angles
*/

#include "pmt_analyzer_showermax.c"

float scan_tandem_angle_416(){
// Makes the canvas
	TCanvas* can = new TCanvas("can", "can", 200, 10, 600, 400);
	can->cd();
	gStyle->SetOptStat(10);
	gStyle->SetOptFit(1110);
	TLegend* legend = new TLegend(0.5, 0.5, 0.9, 0.9);             //Makes the Legend
	legend->SetHeader("(Horizontal(cm),Vertical(cm)) / PMT config / up or down stream", "C");

	float res;

	int pmt = 1;
	int hv;
	float sig;
	float onePEsig;
	int i;

	TMultiGraph *mg = new TMultiGraph();  //tells it theres going to be more than one graph on canvas
	mg->SetTitle("Tandem angle scan; Angle [degrees];PE's"); // (Main;X;Y)

	// First angle scan upstr
	const int num_runs1 = 4; // number of runs on graph
	int runs1[num_runs1];
	float pos1[num_runs1];
	float npe1[num_runs1];
	i=0; runs1[i] = 417; pos1[i] = -1.5;
	i=1; runs1[i] = 418; pos1[i] = -1.5;
	i=2; runs1[i] = 419; pos1[i] = 0;
	i=3; runs1[i] = 420; pos1[i] = 1.5;


	for (int j = 0; j < num_runs1; j++) {
		hv = GetHvFromRun(runs1[j]);
		npe1[j] = GetNpeFromRun(runs1[j]);
		//onePEsig = GetSignalFromPmtAndHV(pmt, hv);
		//sig = GetSignalFromRun(runs1[j]);
		//npe1[j] = ((float)(sig)) / onePEsig;
		//printf("%.1f, %.2f\n", pos1[j], npe1[j]);
	}

	TGraph* gr1 = new TGraph(num_runs1, pos1, npe1);
	legend->AddEntry(gr1, "(10.5,10.83)up / PMT 1,2 / up", "p");
	gr1->SetMarkerColor(1);
	gr1->SetMarkerStyle(8);
	mg->Add(gr1);

	// First angle scan dwnstr
  const int num_runs4 = 4;
	int runs4[num_runs4];
	float pos4[num_runs4];
	float npe4[num_runs4];
	i=0; runs4[i] = 417; pos4[i] = -1.5;
	i=1; runs4[i] = 418; pos4[i] = -1.5;
	i=2; runs4[i] = 419; pos4[i] = 0.;
	i=3; runs4[i] = 420; pos4[i] = 1.5;



	for (int j = 0; j < num_runs4; j++) {
		hv = GetHvFromRun(runs4[j]);
		npe4[j] = GetNpedwnFromRun(runs4[j]);
		//onePEsig = GetSignalFromPmtAndHV(pmt, hv);
		//sig = GetSignalFromRun(runs1[j]);
		//npe1[j] = ((float)(sig)) / onePEsig;
		//printf("%.1f, %.2f\n", pos1[j], npe1[j]);
	}

	TGraph* gr4 = new TGraph(num_runs4, pos4, npe4);
	legend->AddEntry(gr4, "(10.5,10.83)dwn / PMT 1,2 / down", "p");
	gr4->SetMarkerColor(1);
	gr4->SetMarkerStyle(2);
	mg->Add(gr4);

	// Second angle scan upstr
	const int num_runs2 = 2;
	int runs2[num_runs2];
	float pos2[num_runs2];
	float npe2[num_runs2];
        i=0; runs2[i] = 423; pos2[i] = 11.5;
        i=1; runs2[i] = 424; pos2[i] = 1.5;


        for (int j = 0; j < num_runs2; j++) {
                hv = GetHvFromRun(runs2[j]);
                npe2[j] = GetNpeFromRun(runs2[j]);
        }

        TGraph* gr2 = new TGraph(num_runs2, pos2, npe2);
	legend->AddEntry(gr2, "(10.29,12.58)up / PMT 1,2 / up", "p");
	gr2->SetMarkerColor(2);
	gr2->SetMarkerStyle(8);
	mg->Add(gr2);

	// Second angle scan dwnstr
	const int num_runs5 = 2;
	int runs5[num_runs5];
	float pos5[num_runs5];
	float npe5[num_runs5];
				i=0; runs5[i] = 423; pos5[i] = 11.5;
				i=1; runs5[i] = 424; pos5[i] = 1.5;


				for (int j = 0; j < num_runs5; j++) {
								hv = GetHvFromRun(runs5[j]);
								npe5[j] = GetNpedwnFromRun(runs5[j]);
				}

				TGraph* gr5 = new TGraph(num_runs5, pos5, npe5);
	legend->AddEntry(gr5, "(10.29,12.58) / PMT 1,2 / down", "p");
	gr5->SetMarkerColor(2);
	gr5->SetMarkerStyle(2);
	mg->Add(gr5);

	// Third angle scan upstr
	const int num_runs3 = 2;
	int runs3[num_runs3];
	float pos3[num_runs3];
	float npe3[num_runs3];
        i=0; runs3[i] = 425; pos3[i] = 1.5;
        i=1; runs3[i] = 426; pos3[i] = 1.5;

        for (int j = 0; j < num_runs3; j++) {
                hv = GetHvFromRun(runs3[j]);
                npe3[j] = GetNpeFromRun(runs3[j]);
        }

        TGraph* gr3 = new TGraph(num_runs3, pos3, npe3);
	legend->AddEntry(gr3, "(10.29,12.58)up / PMT 2,1 / up", "p");
	gr3->SetMarkerColor(3);
	gr3->SetMarkerStyle(8);
	mg->Add(gr3);






	// Third angle scan upstr
	const int num_runs6 = 2;
	int runs6[num_runs6];
	float pos6[num_runs6];
	float npe6[num_runs6];
				i=0; runs6[i] = 425; pos6[i] = 1.5;
				i=1; runs6[i] = 426; pos6[i] = 1.5;

				for (int j = 0; j < num_runs6; j++) {
								hv = GetHvFromRun(runs6[j]);
								npe6[j] = GetNpedwnFromRun(runs6[j]);
				}

	TGraph* gr6 = new TGraph(num_runs6, pos6, npe6);
	legend->AddEntry(gr6, "(10.29,12.58) / PMT 2,1 / down", "p");
	gr6->SetMarkerColor(3);
	gr6->SetMarkerStyle(2);
	mg->Add(gr6);


	mg->Draw("AP");
	legend->Draw();

	return 0.0;
}
