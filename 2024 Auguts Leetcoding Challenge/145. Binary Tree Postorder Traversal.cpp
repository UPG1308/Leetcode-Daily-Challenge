class Solution {
public:
    void postOrder(TreeNode* root, vector<int>& list){
        if(root == NULL) return;
        postOrder(root -> left, list);
        postOrder(root -> right, list);
        list.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        postOrder(root, list);
        return list;
    }
};
