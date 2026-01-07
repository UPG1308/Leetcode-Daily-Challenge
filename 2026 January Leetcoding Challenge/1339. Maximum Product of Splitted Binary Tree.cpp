/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long total = 0, ans = 0, MOD = 1e9 + 7;
    void dfs1(TreeNode* root){
        if(root == NULL) return ;
        total += root -> val;
        dfs1(root -> left);
        dfs1(root -> right);
    }

    int dfs2(TreeNode* root){
        if(root == NULL) return 0;
        int leftSum = dfs2(root -> left);
        int rightSum = dfs2(root -> right);
        ans = max({ans, 1LL * leftSum * (total - leftSum), 1LL * rightSum * (total - rightSum)});
        return (1LL * root -> val + leftSum + rightSum);
    }

    int maxProduct(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        return ans % MOD;
    }
};
