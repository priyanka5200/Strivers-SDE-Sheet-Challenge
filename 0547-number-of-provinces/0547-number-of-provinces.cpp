class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected,
             vector<int> adj[]) {
        visited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, isConnected, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, 0);
        vector<int> adj[n];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, isConnected, adj);
                cnt++;
            }
        }
        return cnt;
    }
};