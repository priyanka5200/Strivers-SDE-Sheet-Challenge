class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>&path, vector<int>adj[]) {
        vis[node] = 1;
        path[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if(dfs(it, vis, path, adj) == true) {
                    return true;
                }
            }
           else  if (path[it] == true) {
                return true;
            }
        }
        path[node] = 0;
        return false;

    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<int> adj[n];
        vector<int> vis(n+1, 0);
        vector<int> path(n+1, 0);
        for (auto it : pre) {
            vector<int> data = it;
            int a = data[0];
            int b = data[1];
            adj[a].push_back(b);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj) == true)
                    return false;
            }
        }
        return true;
    }
};