class Tree {
    // Function to serialize a tree and return a list containing nodes of tree.
    public ArrayList<Integer> serialize(Node root) {
        // code here
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        ArrayList<Integer> ans=new ArrayList<>();
        ans.add(root.data);
        while(!q.isEmpty()){
            Node curr=q.poll();
            if(curr.left!=null){
                q.add(curr.left);
                ans.add(curr.left.data);

            }
            else{
                ans.add(-1);
            }
            if(curr.right!=null){
                q.add(curr.right);
                ans.add(curr.right.data);

            }
            else ans.add(-1);
        }
        // System.out.println(ans);
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    public Node deSerialize(ArrayList<Integer> A) {
        // code here
        Node ans=new Node(A.get(0));
        Node head=ans;
        Queue<Node> q=new LinkedList<>();
        q.add(ans);
        int idx=1;
        while(!q.isEmpty()){
            Node curr=q.poll();
            if(A.get(idx)!=-1){
                curr.left=new Node(A.get(idx));
                q.add(curr.left);
            }
            idx++;
            if(A.get(idx)!=-1){
                curr.right=new Node(A.get(idx));
                q.add(curr.right);
            }
            idx++;
        }
        return head;
    }
};
