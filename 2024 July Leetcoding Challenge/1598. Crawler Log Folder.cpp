class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int currentFolder = 0;
        for(string &s: logs){
            if(s.find("../") != string::npos){
                currentFolder = max(0, currentFolder - 1);
            }
            else if(s.find("./") != string::npos){
                continue;
            }
            else{
                currentFolder++;
            }
        }
        return currentFolder;
    }
};
