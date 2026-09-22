class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n+1, false);
        vector<vector<pair<int, int>>> mp(n+1);
        for(int i=0;i<times.size();i++){
            mp[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        int re = 0;
        while(!q.empty()){
            int cur = q.top().second;
            int cur_time = q.top().first;
            q.pop();
            if(visited[cur]) continue;
            visited[cur] = true;
            re = cur_time;
            for(int i=0;i<mp[cur].size();i++){
                q.push({cur_time + mp[cur][i].second, mp[cur][i].first});
            }
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]) return -1;
        }
        return re;
    }
};
