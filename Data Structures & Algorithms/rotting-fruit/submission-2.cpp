class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i+1<m && grid[i+1][j]==1){
                grid[i+1][j] = grid[i][j]+1;
                q.push({i+1, j});
            }
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j] = grid[i][j]+1;
                q.push({i-1, j});
            }
            if(j+1<n && grid[i][j+1]==1){
                grid[i][j+1] = grid[i][j]+1;
                q.push({i, j+1});
            }
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1] = grid[i][j]+1;
                q.push({i, j-1});
            }

        }
        int re = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
                re = max(re, grid[i][j]);
            }
        }
        return max(re-2, 0);
    }
};
