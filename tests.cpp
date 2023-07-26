#include <iostream>
#include "barchartanimate.h"
using namespace std;

/// This function tests the default Constructor for the Bar class.
/// if all tests pass then it returns true
bool testBarDefaultConstructor()
{
	Bar b;
	if (b.getName() != "")
	{
		cout << "testBarDefaultConstructor: getName failed" << endl;
		return false;
	}
	else if (b.getValue() != -1)
	{
		cout << "testBarDefaultConstructor: getValue failed" << endl;
		return false;
	}
	else if (b.getCategory() != "")
	{
		cout << "testBarDefaultConstructor: getCategory failed" << endl;
		return false;
	}
	cout << "testBarDefaultConstructor: all passed!" << endl;
	cout << endl;
	return true;
}
/// This function tests the Constructor with parameters for the Bar class.
// this is where we add values to the bar.
/// if all tests pass then it returns true
bool testBarParamConstructor()
{
	Bar b("Chicago", 9234324, "US");
	Bar c("New York", 398475, "US");
	if (b.getName() != "Chicago")
	{
		cout << "testBarParamConstructor: getName failed" << endl;
		return false;
	}
	else if (b.getValue() != 9234324)
	{
		cout << "testBarParamConstructor: getValue failed" << endl;
		return false;
	}
	else if (b.getCategory() != "US")
	{
		cout << "testBarParamConstructor: getCategory failed" << endl;
		return false;
	}

	cout << "testBarParamConstructor: all passed!" << endl;
	cout << endl;
	return true;
}
// This function tests the defulat Constructor for BarChart class
// This tests adding bars to the barchart using the addBar function, setting the frame, using the clear function, and also the operator[] and the =operator.
// if all tests pass then it returns true
bool testBarChartDefaultConstructor()
{
	BarChart bc;
	BarChart ac(3);
	string frame;
	string name;
	int value;
	string category;
	int numOfBars;
	if (bc.getSize() != 0)
	{
		cout << " testBarChartDefaultConstructor: getSize failed" << endl;
		return false;
	}
	
	ac.addBar("Germany", 12345, "Eroupe");
	ac.addBar("England", 5634, "Eroupe");
	bc = ac;
	bc.setFrame("12");
	if (bc.getFrame() == "")
	{
		cout << "testBarDefualtConstructor: getFrame failed" << endl;
		return false;
	}
	if(bc[0].getCategory() == "" || bc[0].getName() == "" || bc[0].getValue() == -1) {
		cout << "hey" << endl;
		cout << "testBarDefualtConstructor: []operator failed" << endl;
		return false;
	}
	ac.clear();
	bc.clear();
	if (ac.getSize() != 0 || bc.getSize() != 0) {
		cout << "testBarDefualtConstructor: clear failed" << endl;
		return false;
	}

	cout << "testBarChartDefaultConstructor: all passed!" << endl;
	cout << endl;
	
	return true;
}
// this function is a helper function to test my copy constructor.
// returns true if it was copied successfully
bool copied(BarChart b)
{
	if(b.getSize() == 0){
		cout << "testBarChartParamConstructor: addBar failed" << endl;
		return false;
	}
	return true;
}
// This function tests the Parameter Constructor for BarChart class
// This tests adding bars to the barchart using the addBar function, setting the frame, dumping the function for printing, using the clear function, and also the operator[] and the =operator.
// if all tests pass then it returns true
bool testBarChartParamConstructor() {
	BarChart bc(10);
	BarChart ac(10);
	BarChart copy;
	bool worked = true;

	bc.addBar("Chicago", 1233, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	ac.addBar("Germany", 12345, "Eroupe");
	ac.addBar("England", 5634, "Eroupe");
	if(bc.getSize() == 0 || ac.getSize() == 0) {
		cout << " testBarChartParamConstructor: addBar failed" << endl;
		return false;
	}
	worked = copied(bc);
	if(worked == 0){
		return worked;
	}
	if(bc[0].getValue() == -1 || ac[0].getValue() == -1){
		cout << "testBarChartParamConstructor: []operator failed" << endl;
		return false;
	}
	bc.setFrame("23");
	ac.setFrame("Good");
	if(bc.getFrame() == "" || ac.getFrame() == "") {
		cout << "testBarChartParamConstructor: getFrame failed" << endl;
		return false;
	}
	ac = bc;
	copy = bc;
	if(ac[0].getName() != "Chicago" || copy[0].getName() != "Chicago") {
		cout << "testBarChartParamConstructor: =operator failed" << endl;
		return false;
	}
	//Uncommemt lines below to use the dump function
	/*
	stringstream ss("");
	bc.dump(ss);
	cout << ss.str();
	ac.dump(cout);
	*/
	ac.clear();
	bc.clear();
	if(bc.getSize() != 0 || ac.getSize() != 0){
		cout << "testBarChartParamConstructor: clear failed" << endl;
		return false;
	}
	cout << "testBarChartParamConstructor: all passed!" << endl;
	cout << endl;
	return true;
}
// This function tests the Bar Chart Animate class.
// checks if we opened the file correctly and if we store all the values to their correct location.
bool testBarChartAnimate() {

	string fileName = "citaaies.txt";
	ifstream inFile(fileName);
	if (!inFile.is_open())
	{
		cout << "testBarChartAnimate: file failed" << endl;
		return false;
	}
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

	if(title == "" || source == "" || xlabel == ""){
		cout << "testBarChartAnimate: string storage failed" << endl;
		return false;
	}
	if(bca.getSize() == 0){
		cout << "testBarChartAnimate: getSize failed" << endl;
		return false;
	}
	if(bca[0].getFrame() == "") {
		cout << "testBarChartAnimate: getFrame failed" << endl;
		return false;
	}

	cout << "testBarChartAnimate: all passed!" << endl;
	cout << endl;
	return true;
}

int main()
{
	cout << endl;
	cout << "Testing Bar Default Constructor... " << endl;
	testBarDefaultConstructor();
	cout << "Testing Bar Parameter Constructor... " << endl;
	testBarParamConstructor();
	cout << "Testing BarChart Default Constructor... " << endl;
	testBarChartDefaultConstructor();
	cout << "Testing BarChart Parameter Constructor... " << endl;
	testBarChartParamConstructor();
	cout << "Testing BarChartAnimate..." << endl;
	testBarChartAnimate();
	
	return 0;
}