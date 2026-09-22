class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> P(m, vector<bool>(n, false));
        vector<vector<bool>> A(m, vector<bool>(n, false));
        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;
        for(int i=0;i<m;i++){
            pq.push({i, 0});
            P[i][0] = true;
            aq.push({i, n-1});
            A[i][n-1] = true;
        }
        for(int j=0;j<n;j++){
            pq.push({0, j});
            P[0][j] = true;
            aq.push({m-1, j});
            A[m-1][j] = true;
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(P[i][j]) cout << '1';
        //         else cout << '0';
        //     }
        //     cout << endl;
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(A[i][j]) cout << '1';
        //         else cout << '0';
        //     }
        //     cout << endl;
        // }
        while(!pq.empty()){
            int i = pq.front().first;
            int j = pq.front().second;
            pq.pop();
            if(i+1<m && !P[i+1][j] && heights[i+1][j]>=heights[i][j]){
                pq.push({i+1, j});
                P[i+1][j] = true;
            }
            if(i-1>=0  && !P[i-1][j] && heights[i-1][j]>=heights[i][j]){
                pq.push({i-1, j});
                P[i-1][j] = true;
            }
            if(j+1<n  && !P[i][j+1] && heights[i][j+1]>=heights[i][j]){
                pq.push({i, j+1});
                P[i][j+1] = true;
            }
            if(j-1>=0  && !P[i][j-1] && heights[i][j-1]>=heights[i][j]){
                pq.push({i, j-1});
                P[i][j-1] = true;
            }
        }
        while(!aq.empty()){
            int i = aq.front().first;
            int j = aq.front().second;
            aq.pop();
            if(i+1<m  && !A[i+1][j] && heights[i+1][j]>=heights[i][j]){
                aq.push({i+1, j});
                A[i+1][j] = true;
            }
            if(i-1>=0  && !A[i-1][j] && heights[i-1][j]>=heights[i][j]){
                aq.push({i-1, j});
                A[i-1][j] = true;
            }
            if(j+1<n  && !A[i][j+1] && heights[i][j+1]>=heights[i][j]){
                aq.push({i, j+1});
                A[i][j+1] = true;
            }
            if(j-1>=0  && !A[i][j-1] && heights[i][j-1]>=heights[i][j]){
                aq.push({i, j-1});
                A[i][j-1] = true;
            }
        }
        vector<vector<int>> re;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(P[i][j] && A[i][j]) re.push_back({i, j});
            }
        }
        return re;
    }
};
