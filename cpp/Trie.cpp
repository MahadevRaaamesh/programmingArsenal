#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
    public:
        vector<int> count;
        vector<TrieNode*>child;
        TrieNode()
        {
            for(int i=0;i<26;i++){
                count[i]=0;
            }
            child.resize(26);
        }
}

class Trie{

    private:
        TrieNode* root;
    public:
}