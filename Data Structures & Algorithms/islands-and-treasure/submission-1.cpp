class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return;
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0) q.push({i, j});
        while(!q.empty()){
            
            int i = q.front().first;
            int j = q.front().second;
            // cout << i << ' ' << j << endl;
            q.pop();
            if(i+1 <m && grid[i+1][j]==INT_MAX){
                grid[i+1][j] = grid[i][j]+1;
                q.push({i+1, j});
            } 
            if(i-1>=0 && grid[i-1][j]==INT_MAX){
                grid[i-1][j] = grid[i][j]+1;
                q.push({i-1, j});
            } 
            if(j+1<n && grid[i][j+1]==INT_MAX){
                grid[i][j+1] = grid[i][j]+1;
                q.push({i, j+1});
            } 
            if(j-1>=0 && grid[i][j-1]==INT_MAX){
                grid[i][j-1] = grid[i][j]+1;
                q.push({i, j-1});
            } 
        }
        return;
    }
};
