class Solution
{
public:
    int countLetters(string str);
};

int Solution :: countLetters(string str)
{
    int n = str.length();
    vector<int> good(n,1);
    
    for(int i = n-2; i >= 0; i--)
        if(str[i] == str[i+1])
            good[i] = good[i+1] + 1;
    
    return accumulate(good.begin(), good.end(), 0);
    
}
