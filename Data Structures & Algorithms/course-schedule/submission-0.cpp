class Solution {
public:
    void dfs(int start, vector<vector<int>> &adj, vector<int> &visited, bool &loop){
        if(visited[start]==2) return;
        if(visited[start]==1){
            loop = true;
            return;
        }
        visited[start] = 1;
        for(int i=0;i<adj[start].size();i++){
            dfs(adj[start][i], adj, visited, loop);
        }
        visited[start] = 2;
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses, 0);
        bool loop = false;
        for(int i=0;i<numCourses;i++){
            dfs(i, adj, visited, loop);
            if(loop) return false;
        }
        return true;
    }
};
