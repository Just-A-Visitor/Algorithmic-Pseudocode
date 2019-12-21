#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string str1, string str2)
{
        int row = str1.length() + 1;
        int col = str2.length() + 1;

        vector<vector<int>> lcs(row, vector<int> (col, 0));

        /* LCS[i][j] represents the lcs of the first i characters of str1
         * and first j characters of str2 
         */
         
        for(int i = 1; i <= str1.length(); i++)
        {
                for(int j = 1; j <= str2.length(); j++)
                {
                        // If the last character match, take it
                        if(str1[i-1] == str2[j-1])
                                lcs[i][j] = 1 + lcs[i-1][j-1];
                        
                        else
                                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
        }

        return lcs[str1.length()][str2.length()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
