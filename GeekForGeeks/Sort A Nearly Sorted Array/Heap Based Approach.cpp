#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort_a_nearly_sorted_array(vector<int> &a, int k);
};

void Solution :: sort_a_nearly_sorted_array(vector<int> &a, int k)
{
    // Size
    int n = a.size();
    
    // Create the min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    // Fill the first (k+1) elements in the min heap 
    for(int i=0; i<(k+1); i++)
        minHeap.push(a[i]);
    
    int leftIndex = 0;
    int rightIndex = (k+1);
    
    // As long as the array is not overwritten, repeat
    while(leftIndex<n)
    {
        // Extract the minimum element
        int minElement = minHeap.top();
        minHeap.pop();
        
        // Put the minimum in the correct place
        a[leftIndex] = minElement;
        
        // Push one element to keep the size of the  minHeap as (k+1 
        if(rightIndex < n) minHeap.push(a[rightIndex]);
        
        // Increment both the indexes
        
        leftIndex++;
        rightIndex++;
    }
}

void scanVector(vector<int> &a)
{
    for(auto &ele:a)
        cin >> ele;
}

void printVector(vector<int> &a)
{
    for(auto ele:a)
        cout << ele << " ";
    
    cout << endl;    
}

int main() 
{
    int n;
    cin >> n;
    
    int k;
    cin >> k;
    
    vector<int> a(n);
    scanVector(a);
    
    Solution myObject;
    myObject.sort_a_nearly_sorted_array(a,k);
    
    printVector(a);
	return 0;
}

/*
8 4
10 9 8 7 4 70 60 50
*/
