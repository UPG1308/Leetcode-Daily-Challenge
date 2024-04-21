class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for(int edge[]: edges){
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        boolean vis[] = new boolean[n];
        vis[source] = true;
        return dfs(source, vis, adj, destination);
    }
    public boolean dfs(int node, boolean[] vis, ArrayList<ArrayList<Integer>> adj, int destination){
        vis[node] = true;
        if(node == destination) return true;
        for(int adjNode: adj.get(node)){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, adj, destination)) return true;
            }
        }
        return false;
    }
}
