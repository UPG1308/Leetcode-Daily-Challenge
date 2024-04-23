class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> ans = new ArrayList<>();
        if(n == 1) {ans.add(0); return ans;}
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++) adj.add(new ArrayList<>());
        int indegree[] = new int[n];
        for(int edge[]: edges){
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        int remaining = n;
        boolean vis[] = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1) q.offer(i);
        }
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int node = q.poll();
                ans.add(node);
                remaining--;
                vis[node] = true;
                for(int adjNode: adj.get(node)){
                    indegree[adjNode]--;
                    if(!vis[adjNode] && indegree[adjNode] == 1){
                        q.offer(adjNode);
                    }
                }
            }     
            if(remaining == 0) break;
            else ans.clear();
        }
        return ans;
    }
}
