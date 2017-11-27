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
