class Solution {
public:
    void sumRootToLeaf(TreeNode* root, int val, int &sum){
        if(root == NULL) return;
        val = (val << 1) + root -> val;
        if(root -> left == NULL && root -> right == NULL) {
            sum += val;
            return;
        }
        if(root -> left != NULL) sumRootToLeaf(root -> left, val, sum);
        if(root -> right != NULL) sumRootToLeaf(root -> right, val, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        sumRootToLeaf(root, 0, sum);
        return sum;
    }
};
