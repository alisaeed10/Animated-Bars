// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// CREATIVE COMPONENT: once you uncommemt the lines from 152 to 157, you would be able to use the creative component. 
// What it does is, you can change the speed of the both the bar inforation and the speed of the informations thaty is being processed.
// How To Use: its gonna frist prompt you to enter a number to change the speed of the bars. then its gonna prompht you to enter a number to edit the speed to process the information in.
//
// Adam Koehler
// U. of Illinois, Chicago
// Fall 2022
//
// Original iteration of program developed by:
// Shanon Reckinger
// U. of Illinois, Chicago

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;

int main() {
	string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);

	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, 12, 10);
	bca.animate(cout, 12, -1);

	return 0;
}
