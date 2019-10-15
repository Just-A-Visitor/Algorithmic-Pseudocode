class Solution
{
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern);
};

/* Returns true if the matching is satisfied */
bool isValidPattern(string &query, string &pattern)
{
    char queryChar, patternChar;
    int index = 0;
    
    // Traverse the query and keep matching the characters
    for(int i=0; i<query.length(); i++)
    {
        queryChar = query[i];
        
        // If pattern has finished, take default character
        if(index >= pattern.length())
            patternChar = '#';
        else
            patternChar = pattern[index];
        
        // Capital Letters must match. If yes, increment pattern
        if(queryChar>='A' and queryChar<='Z')
        {
            if(queryChar==patternChar)
                index++;
            else return false;
        }
        
        // Small letters may or may not match
        // If it matches, increment pattern
        else if(queryChar == patternChar) index++;
    }
    
    // The pattern must be empty by now
    return index>=pattern.length();
}

/* Fills the answer according to camelcase matching */
vector<bool> Solution :: camelMatch(vector<string>& queries, string pattern)
{
    vector<bool> answer;
    for(auto &str : queries)
        answer.push_back(isValidPattern(str, pattern));
    return answer;
}
