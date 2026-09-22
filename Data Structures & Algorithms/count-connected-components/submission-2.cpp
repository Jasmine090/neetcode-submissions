class Solution {
public:
    void dfs(int pre, int cur, vector<vector<int>> &adj, vector<int> &visited, bool &cnt){
        if(visited[cur]!=0) return;
        visited[cur] = 1;
        for(int i=0;i<adj[cur].size();i++){
            //if(adj[cur][i]==pre) continue;
            dfs(cur, adj[cur][i], adj, visited, cnt);
        }
        visited[cur] = 2;
        cnt = true;
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        int re = 0;
        for(int i=0;i<n;i++){
            bool cnt = false;
            dfs(i, i, adj, visited, cnt);
            if(cnt)re++;
        }
        return re;
    }
};
