class Solution {
public:
    //  int fun(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>&dp)
    //  {
    //     if(i==n-1)
    //     {
    //         return triangle[i][j];
    //     }
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int down =  triangle[i][j] + fun(i+1, j, n, triangle,dp);
    //     int dia = triangle[i][j] + fun(i+1, j+1, n, triangle,dp);
    //     return dp[i][j] = min(down, dia);
    //  }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=n-2; i>=0; i--)
        {
            for(int j=0;j<=i; j++)
            {
                triangle[i][j] += min(triangle[i+1][j] , triangle[i+1][j+1] );
            }
        }
        return triangle[0][0];
        
    }
};