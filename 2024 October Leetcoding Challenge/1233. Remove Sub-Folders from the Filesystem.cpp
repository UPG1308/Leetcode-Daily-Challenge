struct Node{
    unordered_map<string, Node*> links;
    bool isLeaf = false;
    bool containsKey(string s){
        return links[s]!=NULL;        
    }
    Node* get(string s){
        return links[s];
    }
    void put(string s,Node* node){
        links[s]=node;
    }
    void setEnd(){
        isLeaf = true;
    }
    bool isEnd(){
        return isLeaf;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    bool insert(string word){
        Node* temp = root;
        int lastInd = 0, consecLetters = 0;
        for(int i=0;i<word.size();i++){
            
            if(word[i]=='/'){
                string str = word.substr(lastInd, consecLetters);
                if(!temp -> containsKey(str))
                    temp -> put(str, new Node());
                temp = temp -> get(str);
                lastInd = i, consecLetters = 0;
                if(temp -> isEnd()) return false;
            }
            consecLetters++;                                  
        }
        string lastWord = word.substr(lastInd, consecLetters);
            if(!temp -> containsKey(lastWord))
                temp -> put(lastWord, new Node());
            temp = temp -> get(lastWord);
        temp->setEnd();
        return true;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        for(auto it = folder.begin(); it != folder.end(); it++) cout<<*it<<" ";
        Trie* trie = new Trie();
        for(int i=0;i<folder.size();i++){
            if(trie->insert(folder[i])){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
