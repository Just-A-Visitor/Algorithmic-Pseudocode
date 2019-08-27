#include <bits/stdc++.h>
using namespace std;

/* Returns the number of set bits of a positive integer */
int countSetBits(unsigned int num)
{
    int setBits = 0;
    
    while(num)
    {
        setBits += (num & 1);
        num = num >> 1;
    }
    
    return setBits;
}

int main()
{
    cout << countSetBits(7) << endl;    
	return 0;
}
