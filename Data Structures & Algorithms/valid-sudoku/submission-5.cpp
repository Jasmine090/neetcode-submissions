class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int column[9] = {0};
        int grid[9] = {0};
        for(int i=0;i<board.size();i++){
            int row = 0;
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.') continue;
                int elem = board[i][j]-'0';
                int bit = 1 << (elem-1);
                if((row & bit)
                   || column[j] & bit
                   || grid[(i/3)*3 + (j/3)] & bit
                   ) return false;
                row |= bit;
                column[j] |= bit;
                grid[(i/3)*3 + (j/3)] |= bit;
            }
        }
        return true;
    }
};
