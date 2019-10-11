#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* To use the template just copy the 2 functions and use it */

/* Prints the contents of a vector containing any data type in the cout stream*/
template <typename universal_type>
void printVector(vector<universal_type> &myVector)
{
    cout << endl << "Printing the contents of the vector" << endl;
    
    for(auto ele : myVector)
        cout << ele << " ";
    
    cout << endl << "The vector has been printed" << endl;
}

/* Scans the contents of a vector of any data type*/
/* Assumes that the vector has been resized */
template <typename universal_type>
void scanVector(vector<universal_type> &myVector)
{
    for(auto &ele : myVector)
        cin >> ele;
}


int main()
{
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
