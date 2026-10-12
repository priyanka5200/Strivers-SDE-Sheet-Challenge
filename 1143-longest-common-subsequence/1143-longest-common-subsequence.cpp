class Solution {
public:
    // int lcs(int i, int j, int n , int m , string text1, string text2)
    // {
    //     if(i>=n || j>=m)return 0;
    //     if(text1[i] == text2[j])
    //     {
    //        return  1+lcs(i+1, j+1, n, m, text1, text2);
    //     }
    //     return max(lcs(i+1, j, n, m , text1, text2), lcs(i, j+1, n, m , text1, text2));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
       
        
    }
};