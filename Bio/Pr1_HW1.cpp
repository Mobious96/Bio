#include <iostream>
#include <fstream>
#include <string>
#include "Pattern.h"

using namespace std;
void main() {
	//ImportData[0] - Text
	//ImportData[1] - Pattern
	string *ImportData = new string[2];
	ifstream fin("Input_Pr1_HW1.txt", ios_base::in);
	for (int i = 0; i < 2; i++) 
	{
		getline(fin, ImportData[i]);
		cout << ImportData[i] << endl;
	}
	static int count = PatternCount(ImportData[0], ImportData[1]);
	cout << "count = " << count << endl;
	ofstream fout("Output_Pr1_HW1.txt", ios_base::out | ios_base::trunc);
	fout << PatternCount(ImportData[0], ImportData[1]);
	fout.close();
	system("pause");
	delete[] ImportData;
}