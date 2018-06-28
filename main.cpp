#include<iostream>
#include"Sequence.h"
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	Sequence dna("/data/dna.txt");
	cout<<"The length of the txt file "<<dna.length()<<endl;
	
	cout<<"The number of A is " << dna.numberOf('A') << endl;
	cout << "The number of T is " << dna.numberOf('T') << endl;
	cout << "The number of C is " << dna.numberOf('C') << endl;
	cout << "The number of G is " << dna.numberOf('G') << endl;

	cout << "The longest consecutive sequence is " << dna.longestConsecutive() << endl;
	cout << "The longest repeated sequence is " << nda.longestRepeated() << endl;

}
