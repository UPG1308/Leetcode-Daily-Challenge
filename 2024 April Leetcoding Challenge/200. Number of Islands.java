class Solution {
    public int numIslands(char[][] grid) {
        int n = grid.length, m = grid[0].length;
        DisjointSet ds = new DisjointSet(grid);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    // grid[i][j] = '0';
                    if((i - 1) >= 0 && grid[i - 1][j] == '1') ds.union(i * m + j, (i - 1) * m + j);
                    if((i + 1) < n && grid[i + 1][j] == '1') ds.union(i * m + j, (i + 1) * m + j);
                    if((j - 1) >= 0 && grid[i][j - 1] == '1') ds.union(i * m + j, i * m + (j - 1));
                    if((j + 1) < m && grid[i][j + 1] == '1') ds.union(i * m + j, i * m + (j + 1));
                }
            }
        }
        return ds.count;
    }
}
class DisjointSet{
    int[] parent, size;
    int count;
    DisjointSet(char[][] grid){
        int n = grid.length, m = grid[0].length;
        parent = new int[n * m];
        size = new int[n * m];
        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(grid[i][j] == '1'){
                    parent[i * m + j] = i * m + j;
                    size[i * m + j] = 1;
                    count++;
                }
            }
        }
        System.out.println(count);
    }
    
    int find(int u){
        if(parent[u] != u) parent[u] = find(parent[u]);        
        return parent[u];
    }
    void union(int u, int v){
        int uparU = find(u);
        int uparV = find(v);
        if(uparU == uparV) return;
        if(size[uparU] > size[uparV]){
            parent[uparV] = uparU;
            size[uparU] += size[uparV];
        }
        else{
            parent[uparU] = uparV;
            size[uparV] += size[uparU];
        }
        count--;
    }
}
