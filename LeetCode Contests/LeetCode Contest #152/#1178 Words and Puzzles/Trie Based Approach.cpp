const int ALPHABET_SIZE = 26;

/* The structure of a trie node */
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    int count = 0;
};

/* Creates a new trie node and returns the pointer */
struct TrieNode* getNode()
{
    struct TrieNode* newNode = new TrieNode;

    for(int i = 0; i < ALPHABET_SIZE; i++)
        newNode->children[i] = nullptr;
    
    newNode->count = 0;

    return newNode;
}

/* Inserts the given string to the collection */
void insert(struct TrieNode* root, string str)
{
    struct TrieNode* pCrawl = root;

    for(int i = 0; i < str.length(); i++)
    {
        int index = str[i]-'a';

        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        
        pCrawl = pCrawl->children[index];
    }

    pCrawl->count++;
}

/* Returns the count of strings which are valid */
int search(struct TrieNode* root, string str, bool firstSeen, char firstLetter)
{
    if(!root)
        return 0;
    
    int count = 0;
    
    if(firstSeen)
        count += root->count;
    
    for(int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        
        if(str[i] == firstLetter)
            count += search(root->children[index], str, true, firstLetter);
        else
            count += search(root->children[index], str, firstSeen, firstLetter);
    }

    return count;
}

class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles);
};

vector<int> Solution :: findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
{
    struct TrieNode* root = getNode();
    
    for(auto str : words)
    {
        set<char> temp;
        temp.insert(str.begin(), str.end());
        
        string sorted = "";
        for(auto ele : temp)
            sorted += ele;
        
        insert(root, sorted);
    }
    
    vector<int> count;
    for(auto puzzle : puzzles)
    {
        char firstLetter = puzzle[0];
        sort(puzzle.begin(), puzzle.end());
        count.push_back(search(root, puzzle, false, firstLetter));
    }
    
    return count;
    
}
