class Solution {
    String smallestString = "zzzzzzzzzzzzz";
    StringBuilder currentString = new StringBuilder();
    public String smallestFromLeaf(TreeNode root) {
        if(root == null) return "";
        smallestStringFromLeaf(root);
        return smallestString.toString();
    }
    public void smallestStringFromLeaf(TreeNode root){
        if(root == null) return;
        char c = (char) ('a' + root.val);
        currentString.insert(0, c);
        if(root.left == null && root.right == null)
        if(smallestString.compareTo(currentString.toString()) > 0) smallestString = currentString.toString();
        if(root.left != null) smallestStringFromLeaf(root.left);
        if(root.right != null) smallestStringFromLeaf(root.right);
        currentString.deleteCharAt(0);
        return;

    }
}
