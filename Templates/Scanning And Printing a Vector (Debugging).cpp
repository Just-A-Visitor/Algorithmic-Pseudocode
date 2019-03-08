#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* The cerr stream won't affect the judgement of a program. */
/* You can even submit the same file on online judge without removing debug */


/* Prints the contents of a vector containing any data type in the cerr stream*/
template <typename universal_type>
void printVector(vector<universal_type> &myVector)
{
    cerr << endl << "Printing the contents of the vector" << endl;
    
    for(auto ele : myVector)
        cerr << ele << " ";
    
    cerr << endl << "The vector has been printed" << endl;
}

/* Scans the contents of a vector of any data type*/
/* Assumes that the vector has been resized */
template <typename universal_type>
void scanVector(vector<universal_type> &myVector)
{
    for(auto &ele : myVector)
        cin >> ele;
}


int main() {
	vector<long long int> myVec;
	
	int size;
	cin >> size;
	
	myVec.resize(size);
	
	scanVector(myVec);
	printVector(myVec);
	return 0;
}


/* Test Case  
5
1 2 3 4 5
*/
