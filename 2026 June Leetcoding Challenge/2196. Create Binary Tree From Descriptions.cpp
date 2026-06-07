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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mp;
        set<int> parent, child;
        for(auto it: descriptions){
            int par = it[0], node = it[1], is_left = it[2];
            if(!mp.count(par)) mp[par] = new TreeNode(par);
            if(!mp.count(node)) mp[node] = new TreeNode(node);
            if(is_left) mp[par] -> left = mp[node];
            else mp[par] -> right = mp[node];
            parent.insert(par);
            child.insert(node);
        }
        for(int x: parent){
            if(!child.count(x)) return mp[x];
        }
        return NULL;
    }
};
