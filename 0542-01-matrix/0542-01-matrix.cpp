class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dis(m, vector<int> (n, m+n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dis[i][j] = 0;
                    continue;
                }
                if (i > 0 and dis[i-1][j] != m+n) {
                    dis[i][j] = min(dis[i][j], dis[i-1][j]+1);
                }
                if (j > 0 and dis[i][j-1] != m+n) {
                    dis[i][j] = min(dis[i][j], dis[i][j-1]+1);
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n -1; j >= 0; --j) {
                if (mat[i][j] == 0) {
                    dis[i][j] = 0;
                    continue;
                }
                if (i + 1 < m and dis[i+1][j] != m+n) {
                    dis[i][j] = min(dis[i][j], dis[i+1][j]+1);
                }
                if (j + 1 < n and dis[i][j+1] != m+n) {
                    dis[i][j] = min(dis[i][j], dis[i][j+1]+1);
                }
            }
        }
        
        return dis;  
    }
};