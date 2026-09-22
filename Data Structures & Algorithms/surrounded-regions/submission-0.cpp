class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i, 0});
            }
            if(board[i][n-1]=='O')
                q.push({i, n-1});
        }
        for(int j=1;j<n-1;j++){
            if(board[0][j]=='O')
                q.push({0, j});
            if(board[m-1][j]=='O')
                q.push({m-1, j});
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            board[i][j] = '#';
            if(i+1<m && board[i+1][j]=='O'){
                q.push({i+1, j});
            }
            if(i-1>=0 && board[i-1][j]=='O'){
                q.push({i-1, j});
            }
            if(j+1<n && board[i][j+1]=='O'){
                q.push({i, j+1});
            }
            if(j-1>=0 && board[i][j-1]=='O'){
                q.push({i, j-1});
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
