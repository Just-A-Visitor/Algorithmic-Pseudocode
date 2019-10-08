class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList);
};

/* Returns the the number of nodes in the shortest path to the target word */
int Solution :: ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> hashMap, visited;
    
    // A fancy way to populate a container
    hashMap.insert(wordList.begin(), wordList.end());
    
    queue<pair<string, int>> bfs;
    
    bfs.push(make_pair(beginWord, 1));
    visited.insert(beginWord);
    
    while(!bfs.empty())
    {
        auto currentNode = bfs.front();
        bfs.pop();
        
        string currentString = currentNode.first;
        int currentLevel = currentNode.second;
        
        if(currentString == endWord)
            return currentLevel;
        
        for(auto &ele : currentString)
        {
            for(int i = 'a'; i <= 'z'; i++)
            {
                // Record the previous character to change it back
                char old = ele;
                ele = i;
                
                if(hashMap.count(currentString) and !visited.count(currentString))
                {
                    bfs.push(make_pair(currentString, currentLevel + 1));
                    visited.insert(currentString);
                }
                
                ele = old;
            }
        }
    }
    
    return 0;
}
