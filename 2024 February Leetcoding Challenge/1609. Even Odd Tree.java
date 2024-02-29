class Solution {
    public boolean isEvenOddTree(TreeNode root) {        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean isEven = true;
        int lastValue = 0;
        while(!queue.isEmpty()){
            int size = queue.size();
            lastValue = (isEven)? Integer.MIN_VALUE: Integer.MAX_VALUE;
            for(int i = 0; i < size; i++){
                TreeNode node = queue.poll();
                if((isEven && (node.val % 2 == 0 || lastValue >= node.val)) || (!isEven && (node.val % 2 == 1 || lastValue <= node.val)))
                    return false;
                lastValue = node.val;
                if(node.left != null) queue.offer(node.left);
                if(node.right != null) queue.offer(node.right);
            }
            isEven = !isEven;
        }
        return true;
    }
}
