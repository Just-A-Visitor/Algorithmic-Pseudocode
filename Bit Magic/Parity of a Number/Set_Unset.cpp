#include <bits/stdc++.h>
using namespace std;

/* Parity is 1 if number of set bits is odd */
int Parity(unsigned int num)
{
    // Keep removing the lowest set bit while it exists
    int parity = 0;
    
    while(num)
    {
        parity ^= 1;
        num &= (num-1);
        
    }
    
    return parity;
}

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
    for(int i=0; i<pow(2,10); i++)
    {
        int first  = Parity(i);
        int second = (countSetBits(i) & 1);
        
        assert(first == second);
    }
    
    cout << " Everything is good" << endl;
    
	return 0;
}
