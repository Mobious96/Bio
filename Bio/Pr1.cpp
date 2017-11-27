#include <iostream>
#include <fstream>
#include <string>
#include "Pattern.h"

using namespace std;
void main() {
	//ImportData[0] - Text
	//ImportData[1] - Pattern
	string *ImportData = new string[2];

	//[ Homework #1 ]
	cout << "[ Homework #2 ]" << endl;
	ifstream fin1("Input_Pr1_HW1.txt", ios_base::in);
	ofstream fout1("Output_Pr1_HW1.txt", ios_base::out | ios_base::trunc);
	for (int i = 0; i < 2; i++) 
	{
		getline(fin1, ImportData[i]);
		cout << ImportData[i] << endl;
	}
	int count = PatternCount(ImportData[0], ImportData[1]);
	cout << "count = " << count << endl;
	fout1 << PatternCount(ImportData[0], ImportData[1]);
	fout1.close();
	
	//[ Homework #2]
	cout << "[ Homework #2 ]" << endl;
	string str;
	ifstream fin("Input_Pr1_HW2.txt", ios_base::in);
	ofstream fout("Output_Pr1_HW2.txt", ios_base::out | ios_base::trunc);
	for (int i = 0; i < 2; i++) {
		getline(fin, ImportData[i]);
		cout << ImportData[i] << endl;
	}
	str = FrequentWords(ImportData[0], stoi(ImportData[1]));
	for (int i = 0; i < str.length(); i++)
	{
		if (i % stoi(ImportData[1]) == 0 && i != 0)
			fout << " ";
		fout << str[i];
	}
	fout.close();

	delete[] ImportData;
}