class Solution
{
public:
    int minDominoRotations(vector<int>& a, vector<int>& b);
    int minSteps(vector<int>& source, vector<int>& target, int candidate);
};

/* Returns the min steps to convert every element in target to candidate */
int Solution :: minSteps(vector<int>& source, vector<int>& target, int candidate)
{
    int swap = 0;
    for(int i=0; i<source.size(); i++)
    {
        /*  If candidate is already in place, do nothing
         *  If the candidate is present in the source, swap it
         *  If the candidate is not present in either of them, it cannot be done
         */
        if(target[i]==candidate) continue;
        else if(source[i]==candidate) swap++;
        else return -1;
    }
    
    return swap;
}

/* Returns the min steps to equalize each element in any vector */
int Solution :: minDominoRotations(vector<int>& a, vector<int>& b)
{
    // Get the size, Create the frequncy and candidate vector
    int n = a.size();
    vector<int> freq(7,0);
    vector<int> candidate;
    
    // Fill the frequency vector
    for(int i=0; i<n; i++)
        freq[a[i]]++, freq[b[i]]++;
    
    // Fill the candidate vectpr
    for(int i=1; i<=6; i++)
        if(freq[i]>=n) 
            candidate.push_back(i);
    
    // If there is no candidate, it cannot be done
    if(candidate.size()==0) return -1;
    
    // Variable to store the min steps
    int minCount = INT_MAX;
    
    // Try all the candidate elements (atmost 2)
    for(int i=0; i<candidate.size(); i++)
    {
        // Try to fill the candidate in the top and bottom
        int top = minSteps(b,a,candidate[i]);
        int bot = minSteps(a,b,candidate[i]);
        
        // Update the best outcome
        minCount  = min({minCount, top, bot});
    }
    
    return minCount;
}
