#include<iostream>
#include<fstream>
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

int numberOf(char base)
{
int counter=0;

char *p = all; 
for(int i=0;i<all.strlen;i++)
 {
	 char c=p[i];
	 if(c==base)
	 {counter++;}
 };
return counter;
}

string longestConsecutive()
{


}

string longestRepeated()
{


}
