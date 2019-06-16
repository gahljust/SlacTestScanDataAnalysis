
#include "pmt_analyzer_showermax.c"

void scan_showermax_1b_horiz_151_362_401(){
// Makes the canvas
	TCanvas* can = new TCanvas("can", "can", 200, 10, 800, 700);
	can->cd();
	gStyle->SetOptStat(10);
	gStyle->SetOptFit(1110);
	TLegend* legend = new TLegend(0.7, 0.8, .9, 0.9);             //Makes the Legend
	legend->SetHeader("Vertical(cm) / runs", "C");

	TMultiGraph *mg = new TMultiGraph();  //tells it theres going to be more than one graph on canvas
	mg->SetTitle("Showermax 1b Horizontal Scan; Horizontal Position [cm];PE's"); // (Main;X;Y)

// first horiz scan 151-155
	const int num_runs1 = 4; // number of runs on graph
	float pos1[num_runs1]= {0,-8.5,-7.5,-6.5};
	float npe1[num_runs1] ={159.88,184.28,186.77,161.2};

	TGraph* gr1 = new TGraph(num_runs1, pos1, npe1);
	legend->AddEntry(gr1, "apporx 19 [cm] / 132-151", "p");
	gr1->SetMarkerColor(1);
	gr1->SetMarkerStyle(8);
	mg->Add(gr1);


//second horiz scan 362-370
	const int num_runs2 = 5; // number of runs on graph
	float pos2[num_runs2]= {0,6.5,6,6,1};
	float npe2[num_runs2] = {200.19,166.63,142.9,142.96,191.38};

	TGraph* gr2 = new TGraph(num_runs2, pos2, npe2);
	legend->AddEntry(gr2, "approx 16.5 [cm] / 362-370", "p");
	gr2->SetMarkerColor(2);
	gr2->SetMarkerStyle(8);
	mg->Add(gr2);


//third horiz scan 408-410
	const int num_runs3 = 3; // number of runs on graph
	float pos3[num_runs3]= {0,4,-4.5};
	float npe3[num_runs3] = {193.42,170.05,212.76};

	TGraph* gr3 = new TGraph(num_runs3, pos3, npe3);
	legend->AddEntry(gr3, "?? / 408-410", "p");
	gr3->SetMarkerColor(3);
	gr3->SetMarkerStyle(8);
	mg->Add(gr3);


	mg->Draw("AP");
	legend->Draw();

}
