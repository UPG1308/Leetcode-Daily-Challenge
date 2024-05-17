class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if(root.left != null) root.left = removeLeafNodes(root.left , target);
        if(root.right != null) root.right = removeLeafNodes(root.right , target);
        //both root.right and root.left shouldl be null otherwise the below condition will be false
        return root.right == root.left && root.val == target ? null : root;
    }
}
