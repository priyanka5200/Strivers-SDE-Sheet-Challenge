class Solution {
public:
    bool cycle(int node, vector<int>& vis, vector<int>& path, vector<int> adj[],
               vector<int>& ans) {
        vis[node] = true;
        path[node] = true;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (cycle(it, vis, path, adj, ans) == true) {
                    return true;
                }
            } else if (path[it] == true) {
                return true;
            }
        }
        ans.push_back(node);
        path[node] = false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> vis(n + 1, 0);
        vector<int> path(n + 1, 0);
        vector<int> ans;
        for (auto it : pre) {
            vector<int> data = it;
            int a = data[0];
            int b = data[1];

            adj[b].push_back(a);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if(cycle(i, vis, path, adj, ans))
                {
                    return {};
                }
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};