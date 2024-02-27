/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        int diameter[] = new int[1];
        height(root, diameter);
        return diameter[0];
    }

    private int height(TreeNode root, int[] diameter){
        if(root == null)return 0;
        // if(root.left == null && root.right == null) return 1;
        
        int leftHeight = height(root.left, diameter);
        // if(leftHeight == -1) return -1;
        int rightHeight = height(root.right , diameter);
        // if(rightHeight == -1) return -1;
        diameter[0] = Math.max(diameter[0], leftHeight + rightHeight);
        // if(Math.abs(leftHeight - rightHeight) > 1) return -1;
        return Math.max(leftHeight , rightHeight) + 1;
    }
}
