class Solution {
public:
    void dfs(int prev, int cur, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path, vector<bool> &onloop){
        if(visited[cur]==2) return;
        if(visited[cur]==1){
            for(int i=path.size()-1;i>=0;i--){
                onloop[path[i]]=true;
                if(path[i]==cur) break;
            }
            return;
        }
        visited[cur] = 1;
        path.push_back(cur);
        for(int i=0;i<adj[cur].size();i++){
            if(adj[cur][i]==prev) continue;
            dfs(cur, adj[cur][i], adj, visited, path, onloop);
        }
        path.pop_back();
        visited[cur] = 2; 
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n+1, 0);
        vector<int> path;
        vector<bool> onloop(n+1, false);
        for(int i=1;i<n+1;i++){
            dfs(i, i, adj, visited, path, onloop);
        }

        for(int i=n-1;i>=0;i--){
            if(onloop[edges[i][0]] && onloop[edges[i][1]]){
                return edges[i];
            }
        }
        return {};
    }
};
