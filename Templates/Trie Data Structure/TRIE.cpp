#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* getNode()
{
    struct TrieNode* newNode = new TrieNode;

    for(int i=0; i<ALPHABET_SIZE; i++)
        newNode->children[i] = nullptr;
    
    newNode->isEndOfWord = false;

    return newNode;
}

void insert(struct TrieNode* root, string str)
{
    struct TrieNode* pCrawl = root;

    for(int i=0; i<str.length(); i++)
    {
        int index = str[i]-'a';

        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        
        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode* root, string str)
{
    struct TrieNode* pCrawl = root;
    
    for(int i=0; i<str.length(); i++)
    {
        int index = str[i] - 'a';

        if(!pCrawl or !pCrawl->children[index])
            return false;
        
        pCrawl = pCrawl->children[index];
    }

    return (pCrawl and pCrawl->isEndOfWord);
}

void TestDrive()
{
    struct TrieNode* root = getNode();

    vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    
    for(int i=0; i<keys.size(); i++)
        insert(root, keys[i]);
    
    cout << search(root, "the") << endl;
    cout << search(root, "answe") << endl;
}

int main()
{
    TestDrive();
}
