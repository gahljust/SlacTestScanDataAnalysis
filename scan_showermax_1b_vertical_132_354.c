
#include "pmt_analyzer_showermax.c"

void scan_showermax_1b_vertical_132_354(){
// Makes the canvas
	TCanvas* can = new TCanvas("can", "can", 200, 10, 800, 700);
	can->cd();
	gStyle->SetOptStat(10);
	gStyle->SetOptFit(1110);
	TLegend* legend = new TLegend(0.7, 0.8, .9, 0.9);             //Makes the Legend
	legend->SetHeader("Horizontal(cm) / runs", "C");

	TMultiGraph *mg = new TMultiGraph();  //tells it theres going to be more than one graph on canvas
	mg->SetTitle("Showermax 1b Vertical Scan; Vertical Position [cm];PE's"); // (Main;X;Y)

// first ver scan 132-138
	const int num_runs1 = 7; // number of runs on graph
	float pos1[num_runs1]= {0,0,0,0,-5,-10,-10};
	float npe1[num_runs1] = {171.42,166.99,168.47,166.97,187.15,213.7,213.2};

	TGraph* gr1 = new TGraph(num_runs1, pos1, npe1);
	legend->AddEntry(gr1, "9 [cm] / 132-138", "p");
	gr1->SetMarkerColor(1);
	gr1->SetMarkerStyle(8);
	mg->Add(gr1);


	// second ver scan 139-151
	const int num_runs4 = 11; // number of runs on graph
	float pos4[num_runs4]= {0,5,5,10,11,12,-11,-11.5,-12.5,-11.5,-11};
	float npe4[num_runs4] = {163.48,177.25,171.73,215.85,229.38,217.85,192.99,193.04,173.83,200.42,200.04};

	TGraph* gr4 = new TGraph(num_runs4, pos4, npe4);
	legend->AddEntry(gr4, "8 [cm] / 139-151", "p");
	gr4->SetMarkerColor(4);
	gr4->SetMarkerStyle(8);
	mg->Add(gr4);

//second 354-362
	const int num_runs2 = 8; // number of runs on graph
	float pos2[num_runs2]= {0,-11,-11,-11,-13,-14.5,-14,-1.5};
	float npe2[num_runs2] = {196.42,242.57,243.21,246,226.95,217.24,217.24,200.19};

	TGraph* gr2 = new TGraph(num_runs2, pos2, npe2);
	legend->AddEntry(gr2, "approx 9 [cm] / 354-362", "p");
	gr2->SetMarkerColor(2);
	gr2->SetMarkerStyle(8);
	mg->Add(gr2);

//third ver scan 411-414
	const int num_runs3 = 4; // number of runs on graph
	float pos3[num_runs3]= {0,3,3,5};
	float npe3[num_runs3] = {196.59,208.12,207.9,231.58};

	TGraph* gr3 = new TGraph(num_runs3, pos3, npe3);
	legend->AddEntry(gr3, "?? / 411-414", "p");
	gr3->SetMarkerColor(3);
	gr3->SetMarkerStyle(8);
	mg->Add(gr3);

	//151
		const int num_runs5 = 1; // number of runs on graph
		float pos5[num_runs5]= {1.5};
		float npe5[num_runs5] = {175.64};

		TGraph* gr5 = new TGraph(num_runs5, pos5, npe5);
		legend->AddEntry(gr5, "Vertical Center", "p");
		gr5->SetMarkerColor(1);
		gr5->SetMarkerStyle(29);
		mg->Add(gr5);


	mg->Draw("AP");
	legend->Draw();

}
