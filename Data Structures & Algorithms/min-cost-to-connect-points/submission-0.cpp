class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<vector<int>> edges;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        int re = 0;
        while(!q.empty()){
            int idx = q.top().second;
            int cost = q.top().first;
            q.pop();
            if(visited[idx]) continue;
            visited[idx] = true;
            re += cost;
            cout << idx << endl;
            for(int i=0;i<n;i++){
                if(visited[i]) continue;
                int dist = abs(points[i][0]-points[idx][0]) + abs(points[i][1]-points[idx][1]);
                q.push({dist, i});
            }
        }
        return re;
    }
};
