class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(visited[i][j] || grid[i][j]==0) return 0;
        visited[i][j] = true;
        int re = 1;
        re += dfs(grid, visited, i+1, j);
        re += dfs(grid, visited, i-1, j);
        re += dfs(grid, visited, i, j+1);
        re += dfs(grid, visited, i, j-1);
        return re;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int re = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                re = max(re, dfs(grid, visited, i, j));
            }
        }
        return re;
    }
};
