class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> mp(n);
        for(int i=0;i<flights.size();i++){
            mp[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> visited(n, INT_MAX);
        // auto cmp = [](const vector<int> &a, const vector<int> &b){
        //     return a[0] > b[0];
        // };
        // priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src, 0});
        while(!q.empty()){
            int fee = q.top()[0];
            int idx = q.top()[1];
            int cnt = q.top()[2];
            q.pop();
            if(cnt>k+1){
                continue;
            }
            if(idx==dst) return fee;
            if(cnt > visited[idx]) continue;
            visited[idx] = cnt;
            
            for(int i=0;i<mp[idx].size();i++){
                q.push({fee+mp[idx][i].second, mp[idx][i].first, cnt+1});
            }
        }
        return -1;
    }
};
