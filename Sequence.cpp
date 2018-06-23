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

}

string longestConsecutive()
{


}

string longestRepeated()
{


}
