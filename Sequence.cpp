#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
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
        int size = all.size();
        vector<string> sequence(size);
        for (int i=0;i<size;i++)
            sequence[i] = all.substr(i,size-i);
        
        sort(sequence.begin(),sequence.end());
        
        int maxLength = 0;
        int pos = 0;
        for(int j=0;j<size-1;j++)
        {
           int length = longest(sequence[j],sequence[j+1]);
           if(maxLength<length)
           {
              maxLength = length;
              pos = j;
           }

        }
        
        return sequence[pos].substr(0,maxLength);

}
      

        int Sequence::longest(string str1,string str2)
        {
           int len = min(str1.size(),str2.size());
           for(int i = 0;i<len;i++)
           {
              if(str1[i] != str2[i])
                return i;
           }
           return len;
        }


