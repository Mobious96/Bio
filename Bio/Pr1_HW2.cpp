#include <iostream>
#include <fstream>
#include <string>
#include "Pattern.h"

using namespace std;

void DeleteDuplicates(string &Text, int length) 
{
	for (int i = 0; i < Text.length()-length; i += length)
	{
		int j = i + 1;
		while (j < Text.length())
		{
			if (Text.substr(i, length) == Text.substr(j, length))
				Text.erase(j, length);
			else
				j++;
		}
	}
}

string FrequentWords(string &Text, int k) 
{
	string finalStr = "";
	int maxCount = 0;
	int *count = new int[Text.length() - k + 1];
	for (int i = 0; i < Text.length() - k + 1; i++)
	{
		string Pattern = Text.substr(i, k);
		count[i] = PatternCount(Text, Pattern);
		if (count[i] > maxCount)
			maxCount = count[i];
	}
	for (int i = 0; i < Text.length() - k + 1; i++)
	{
		if (count[i] == maxCount)
		{
			finalStr += Text.substr(i, k);
		}
	}
	DeleteDuplicates(finalStr, k);
	return finalStr;
}

void main()
{
	string *ImportData, str;
	ImportData = new string[2];
	ifstream fin("Input_Pr1_HW2.txt", ios_base::in);
	for (int i = 0; i < 2; i++) {
		getline(fin, ImportData[i]);
		cout << ImportData[i] << endl;
	}
	str = FrequentWords(ImportData[0], stoi(ImportData[1]));
	ofstream fout("Output_Pr1_HW2.txt", ios_base::out | ios_base::trunc);
	for (int i = 0; i < str.length(); i++)
	{
		if (i % stoi(ImportData[1]) == 0 && i != 0)
			fout << " "; 
		fout << str[i];
	}
	fout.close();
	delete[] ImportData;
}