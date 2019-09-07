class Solution
{
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases);
};

vector<string> Solution :: beforeAndAfterPuzzles(vector<string>& phrase)
{
    set<string> store;
    int n = phrase.size();
    
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if(i == j)
                continue;
            
            stringstream first(phrase[i]);
            stringstream second(phrase[j]);
            
            string temp;
            
            vector<string> firstString;
            vector<string> secondString;
            
            while(first >> temp)
                firstString.push_back(temp);
            
            while(second >> temp)
                secondString.push_back(temp);
            
            if(firstString.back() == secondString.front())
            {
                string res = phrase[i];
                
                for(int k = 1; k < secondString.size(); k++)
                    res += " " + secondString[k];
                
                store.insert(res);
            }    
        }
    }
    
    vector<string> ans;
    for(auto ele : store)
        ans.push_back(ele);
    
    return ans;
}
