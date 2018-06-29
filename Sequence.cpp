#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
char* f = (char*)filename.data();
ifstream input(f);
string s;

while(getline(input,s))
{
all += s;
}

}

int Sequence::length()
{
	int length = all.size();
	return length;
}

int Sequence::numberOf(char base)
{
int num = count(all.begin(),all.end(),base);
return num;
}

string Sequence::longestConsecutive()
{
	int max = 1;
	int cur = 1;
	char maxValue;
        char *first=(char*)all.data();
        char *last=(char*)all.data();
        while(*++last)
	{
		if (*first == *last)
			{cur++;}
		else
		{
			if (max < cur)
			{
				max = cur;
				maxValue = first[0];
		
			}
                        first=last;
                        cur=1;
		}
	}
	char *sequence=new char[max];
        for (int j = 0; j < max; j++)
	 {
         sequence[j]=maxValue;
         }
        string seq=sequence;
        delete []sequence;
        return seq;
}

string Sequence::longestRepeated()
{
	int length = 1;
	int max = 1;
	int pos = 0;
	for (int i = 0; i < all.size(); i++)
	{
		for (int j = i+1; j < all.size() - i; j++)
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
	char *sequence = new char [length];
        for (int k = pos; k < length+pos; k++)
		{
                 string maxVa = all.substr(k,1);
                 sequence[k-pos]=maxVa[0];
                }
                 string seq = sequence;
                 delete []sequence;
                 return seq;
}

