class Solution {
public:
    vector<pair<int, int>> stringParse(string& traversal){
        vector<pair<int,int>> s;
        int n = traversal.size();
        for(int i = 0; i < n;){
            int dashCount = 0;
            while(i < n && traversal[i] == '-'){
                dashCount++;
                i++;
            }
            int value = 0;
            while(i < n && traversal[i] != '-'){
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            s.push_back({dashCount, value});
        }
        return s;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> path = stringParse(traversal);
        stack<pair<int, TreeNode*>> st;
        int n = path.size();
        TreeNode* root = NULL;

        for(auto &[depth, value]: path){
            TreeNode* node = new TreeNode(value);
            if(st.empty()) {
                root = node;
                st.push({depth, node});
            }
            else{
                while(!st.empty() && st.top().first >= depth) st.pop();
                TreeNode* currNode = st.top().second;
                if(currNode -> left == NULL) currNode -> left = node;
                else currNode -> right = node;
                st.push({depth, node});
            }
        }
        return root;
    }
};
