class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;
        int left = 0;
        vector<int> re;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                re.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                re.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right;i>=left && top<=bottom;i--){
                re.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom;i>=top && left<=right;i--){
                re.push_back(matrix[i][left]);
            }
            left++;
        }
        return re;
    }
};
