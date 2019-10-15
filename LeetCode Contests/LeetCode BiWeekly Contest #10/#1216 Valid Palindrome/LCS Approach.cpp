class Solution
{
public:
    bool isValidPalindrome(string str, int k);
};

int compute_lcs(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    
    int row = m + 1;
    int col = n + 1;
    
    vector<vector<int>> lcs(row, vector<int>(col,0));
    
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            if(str1[i-1] == str2[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = max({lcs[i-1][j], lcs[i][j-1], lcs[i-1][j-1]});
        }
    }
    
    return lcs[m][n];
}


bool Solution :: isValidPalindrome(string str1, int k)
{
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    
    int remain = str1.length() - compute_lcs(str1, str2);
    
    return remain <= k;
}
