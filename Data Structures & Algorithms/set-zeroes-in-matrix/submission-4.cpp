class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        0,1,2,0
        3,4,5,2
        1,3,1,5
        */
        bool col0 = false;
        bool row0 = false;
        for(int i=0;i<matrix[0].size();i++){
            if(!matrix[0][i]) row0 = true;
        }
        for(int i=0;i<matrix.size();i++){
            if(!matrix[i][0]) col0 = true;
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(!matrix[0][j] || !matrix[i][0]){
                    matrix[i][j] = 0;
                }
            }
        }
        if(col0){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
        if(row0){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
        return;
    }
};
