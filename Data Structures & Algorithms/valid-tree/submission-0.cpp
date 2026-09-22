class Solution {
public:
    void dfs(int last, int start, vector<vector<int>> &adj, vector<int> &visited, bool &looped){
        if(visited[start]==2) return;
        if(visited[start]==1){
            cout << start << endl;
            looped = true;
            return;
        }
        visited[start] = 1;
        for(int i=0;i<adj[start].size();i++){
            if(adj[start][i]==last) continue;
            dfs(start, adj[start][i], adj, visited, looped);
        }
        visited[start] = 2;
        return;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        bool looped = false;
        dfs(0, 0, adj, visited, looped);
        for(int i=0;i<n;i++){
            cout << visited[i] << ' ';
            if(visited[i]!=2) return false;
        }
        return !looped;
    }
};
