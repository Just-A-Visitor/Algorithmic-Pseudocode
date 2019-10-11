class Solution
{
public:
    int numPairsDivisibleBy60(vector<int>& time);
};

/* Returns the number of pairs whose sum is divisible by 60 */
int Solution :: numPairsDivisibleBy60(vector<int>& a)
{
    // The reference for modular arithmetic
    int ref=60;
	
    // Populate the map in modular arithemtic
    unordered_map<int,int> count;
    for(auto ele : a)
        count[ele%ref]++;
		
    // Traverse from 1 to 29 and update answer
    int answer=0;
    for(int i=1; i<ref/2; i++)
        answer += count[i]*count[ref-i];
		
    // Deal with numbers with identical complement
    answer += count[0]*(count[0]-1)/2;
    answer += count[ref/2]*(count[ref/2]-1)/2;
    
    return answer;
}
