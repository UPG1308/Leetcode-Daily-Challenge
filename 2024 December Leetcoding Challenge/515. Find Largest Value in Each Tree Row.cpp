class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(root == NULL) return ans;
        while(!q.empty()){
            long long size = q.size(), maxval = -1e17;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                maxval = fmaxl(maxval, node -> val);
                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};
