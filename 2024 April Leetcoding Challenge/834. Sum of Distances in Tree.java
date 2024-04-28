class Solution {
    int[] nodes, sum;
    ArrayList<ArrayList<Integer>> adj;
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        adj = new ArrayList<>();
        for(int i = 0;i < n; i++) adj.add(new ArrayList<>());
        for(int[] edge: edges){
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        nodes = new int[n];
        sum = new int[n];
        postOrder(0, -1);
        postOrder2(0,-1, n);
        return sum;
    }

    public void postOrder(int node, int par){
        for(int adjNode: adj.get(node)){
            if(adjNode == par) continue;
            postOrder(adjNode, node);
            sum[node] += sum[adjNode] + nodes[adjNode];
            nodes[node] += nodes[adjNode];
        }
        nodes[node]++;
    }
    public void postOrder2(int node,int par, int n){
        for(int adjNode: adj.get(node)){
            if(adjNode == par) continue;
            sum[adjNode] = sum[node] - nodes[adjNode] + n - nodes[adjNode];
            postOrder2(adjNode, node, n);
        }
    }
}
