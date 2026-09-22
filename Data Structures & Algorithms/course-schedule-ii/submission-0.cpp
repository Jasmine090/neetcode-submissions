class Solution {
public:
    void dfs(int start, vector<vector<int>> &adj, vector<int> &visited, vector<int> &re, bool &looped){
        if(visited[start]==2) return;
        else if(visited[start]==1){
            looped = true;
            return;
        }
        visited[start] = 1;
        for(int i=0;i<adj[start].size();i++){
            dfs(adj[start][i], adj, visited, re, looped);
        }
        re.push_back(start);
        visited[start] = 2;
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses, 0);
        bool looped = false;
        vector<int> re;
        for(int i=0;i<numCourses;i++){
            dfs(i, adj, visited, re, looped);
            if(looped) return {};
        }
        return re;
    }
};
