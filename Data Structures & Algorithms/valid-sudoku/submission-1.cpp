class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<set<char>> column(9);
        vector<set<char>> grid(3);
        for(int i=0;i<board.size();i++){
            set<char> row;
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.') continue;
                if(row.count(board[i][j])
                   || column[j].count(board[i][j])
                   || grid[j/3].count(board[i][j])
                   ) return false;
                row.insert(board[i][j]);
                column[j].insert(board[i][j]);
                grid[j/3].insert(board[i][j]);
            }
            if(i==2 || i==5 ||i==8){
                for(int k=0;k<3;k++){
                    for(const auto &elem : grid[k]){
                        cout << elem << ' ';
                    }
                    cout << endl;
                }
                for(int k=0;k<3;k++) grid[k].clear();
            }
        }
        return true;
    }
};
