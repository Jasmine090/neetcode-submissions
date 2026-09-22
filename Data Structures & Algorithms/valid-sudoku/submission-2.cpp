class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int column[9][9] = {0};
        int grid[3][9] = {0};
        for(int i=0;i<board.size();i++){
            int row[9] = {0};
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.') continue;
                int elem = board[i][j]-'0';
                if(row[elem-1]
                   || column[j][elem-1]
                   || grid[j/3][elem-1]
                   ) return false;
                row[elem-1] = 1;
                column[j][elem-1] = 1;
                grid[j/3][elem-1] = 1;
            }
            if(i==2 || i==5 ||i==8){
                for(int k=0;k<3;k++){
                    for(int p=0;p<9;p++){
                        grid[k][p] = 0;
                    }
                }
            }
        }
        return true;
    }
};
