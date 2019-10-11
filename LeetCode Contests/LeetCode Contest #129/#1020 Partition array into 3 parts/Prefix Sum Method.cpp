class Solution
{
public:
    bool canThreePartsEqualSum(vector<int>& A);
};

bool Solution :: canThreePartsEqualSum(vector<int>& a)
{
    int sum = accumulate(a.begin(), a.end(), 0);
    
    if(sum%3!=0) return false;
    
    int subSum = sum/3;
    
    bool firstFound=false, secondFound = false, thirdFound = false;
    
    int prefixSum=0;
    for(auto ele : a)
    {
        prefixSum += ele;
        if(!firstFound && prefixSum==subSum) firstFound = true;
        else if(firstFound && !secondFound && prefixSum==subSum*2) secondFound = true;
        else if(firstFound && secondFound && prefixSum==subSum*3) thirdFound = true;
    }
    
    return (firstFound && secondFound && thirdFound);
        
}
