#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
ifstream fin(filename);
string s;

while(getline(fin,s))
{
s.erase(s.strlen()-1,1);
all += s;
}

}

int Sequence::length()
{
int length = all.strlen();
return length;
}

int Sequence::numberOf(char base)
{
int num = count(all.begin(),all.end(),'base');
return num;
}

string Sequence::longestConsecutive()
{
	int max = 1;
	int cur = 1;
	string maxValue;
	for (int i = 0; i < all.size()-1; i++)
	{
		if (all.substr(i, 1) == all.substr(i + 1, 1))
			cur++;
		else
		{
			if (max < cur)
			{
				max = cur;
				maxValue = all.substr(i, 1);
				cur = 1;
			}
		}
	}
	for (int j = 0; j < max; j++)
		return maxValue;
}

string Sequence::longestRepeated()
{
	int length = 1;
	int max = 1;
	int pos = 0;
	for (int i = 0; i < all.size() - 1; i++)
	{
		for (int j = i+1; j < all.size() - i - 1; j++)
		{
			if (all.substr(j, 1) == all.substr(i, 1))
			{
				for (int m = j + 1; m < all.size() - j - 1; m++)
				{
					if (all.substr(m, 1) == all.substr(i + 1, 1))
					{
						length++;
						i++;
					}
					else
					{
						if (max < length)
						{
							max = length;
							pos = i;
						}
					}
				}

			}
		}
	}
	for (int k = 0; k < length; k++)
		return all.substr(k, 1);
}

