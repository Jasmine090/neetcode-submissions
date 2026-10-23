class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // (i, j) => (j, n-1-i)
        int n = matrix.size();
        int hn = n/2+1;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                int last_i = i;
                int last_j = j;
                int it = last_j;
                int jt = n-1-last_i;
                int last_v = matrix[last_i][last_j];
                int cnt = 4;
                while(cnt){
                    int tmp = matrix[it][jt];
                    matrix[it][jt] = last_v;
                    last_v = tmp;
                    last_i = it;
                    last_j = jt;
                    it = last_j;
                    jt = n-1-last_i;
                    cnt--;
                }
            }
        }
        return;
    }
};
