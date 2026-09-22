class Solution {
public:
    void dfs(int cur, vector<vector<int>> &adj, vector<bool> &visited, bool &cnt){
        if(visited[cur]) return;
        visited[cur] = true;
        for(int i=0;i<adj[cur].size();i++){
            dfs(adj[cur][i], adj, visited, cnt);
        }
        cnt = true;
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        int re = 0;
        for(int i=0;i<n;i++){
            bool cnt = false;
            dfs(i, adj, visited, cnt);
            if(cnt)re++;
        }
        return re;
    }
};
