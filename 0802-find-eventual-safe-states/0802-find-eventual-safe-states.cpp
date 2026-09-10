class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans;
        vector<int>outdegree(n);
        vector<int>adj[n];
        queue<int>q;

        for(int i=0; i<n; i++)
        {
            for(int it : graph[i])
            {
                adj[it].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if(outdegree[i]==0)
            {
                q.push(i);
            }

        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node])
            {
                outdegree[it]--;
                if(outdegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};