#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int moveCount = 0;
    int desiredCount = 0;
    void tower_of_hanoi(int n, int source, int aux, int target);
};

void Solution :: tower_of_hanoi(int n, int source, int aux, int target)
{
    if(n == 1)
    {
        moveCount ++;
        if(moveCount == desiredCount)
            cout << source << " " << target << endl;

        return;
    }
    
    tower_of_hanoi(n-1, source, target, aux);
  
    moveCount++;
    if(moveCount == desiredCount)
        cout << source << " " << target << endl;

    tower_of_hanoi(n-1, aux, source, target);
}

int main()
{
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        Solution s;
        int n, desiredCount;
        cin >> n >> desiredCount;
        
        s.desiredCount = desiredCount;
        s.tower_of_hanoi(n, 1, 2, 3);
    }
    return 0;
}
