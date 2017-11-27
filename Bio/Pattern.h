#pragma once
#include <string>
using namespace std;
int PatternCount(string &Text, string &Pattern)
{
	int count = 0;
	for (int i = 0; i < Text.length() - Pattern.length() + 1; i++) //n - l + 1
	{
		if (Text.substr(i, Pattern.length()) == Pattern) count++;
	}
	return count;
}

void DeleteDuplicates(string &Text, int length)
{
	for (int i = 0; i < Text.length() - length; i += length)
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