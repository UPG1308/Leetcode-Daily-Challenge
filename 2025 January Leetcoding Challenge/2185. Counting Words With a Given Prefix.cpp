class TrieNode{
public:
    TrieNode* links[26];
    int prefCount = 0;
    bool isEnd = false;

    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }

    void put(char c, TrieNode* node){
        links[c - 'a'] = node;
    }

    TrieNode* get(char c){
        return links[c - 'a'];
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string& word){
        TrieNode* node = root;
        for(char c: word){
            if(!node -> containsKey(c)){
                node -> put(c, new TrieNode());
            }
            node = node -> get(c);
            node -> prefCount++;
        }
        node -> isEnd = true;
    }

    int prefixCount(string& pref){
        TrieNode* node = root;
        for(char c: pref){
            if(!node -> containsKey(c)) return 0;
            node = node -> get(c);
        }
        return node -> prefCount;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie* trie = new Trie();
        for(string s: words) trie -> insert(s);
        return trie -> prefixCount(pref);
    }
};
