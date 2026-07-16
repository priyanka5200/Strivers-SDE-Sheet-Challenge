class Solution {
public:
    void dfs(int node, vector<int>adj[], vector<bool>&vis)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(vis[it] != true)
            {
                dfs(it, adj, vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& mat) {
        int V = mat.size();
        vector<int>adj[V];

        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(mat[i][j] == 1 & i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool>vis(V,0);
        for(int i=0; i<V; i++)
        {
            if(vis[i]!=true)
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};