class Solution {
public:
    bool DFS(vector<vector<char>>& board, pair<int, int> cur, string &word, int w_idx, vector<vector<bool>>& visited){
        int m = board.size();
        int n = board[0].size();
        
        if(cur.first<0 || cur.first>=m || cur.second<0 || cur.second>=n) return false;
        if(visited[cur.first][cur.second]) return false;
        if(board[cur.first][cur.second] != word[w_idx]) return false;
        if(w_idx==int(word.size())-1) return true;
        
        
        visited[cur.first][cur.second] = true;
        if(DFS(board, {cur.first-1, cur.second}, word, w_idx+1, visited)) return true;
        if(DFS(board, {cur.first+1, cur.second}, word, w_idx+1, visited)) return true;
        if(DFS(board, {cur.first, cur.second-1}, word, w_idx+1, visited)) return true;
        if(DFS(board, {cur.first, cur.second+1}, word, w_idx+1, visited)) return true;
        visited[cur.first][cur.second] = false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> starts;
        vector<vector<bool>> visited;
        for(int i=0;i<m;i++){
            vector<bool> tmp;
            for(int j=0;j<n;j++){
                tmp.push_back(false);
                if(board[i][j]==word[0]){
                    starts.push_back({i, j});
                }
            }
            visited.push_back(tmp);
        }
        for(int i=0;i<starts.size();i++){
            if(DFS(board, starts[i], word, 0, visited)) return true;
        }
        return false;
    }
};
