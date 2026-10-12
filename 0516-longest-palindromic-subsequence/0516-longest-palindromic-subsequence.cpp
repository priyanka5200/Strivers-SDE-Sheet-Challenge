class Solution {
public:
    // int lcs(int i, int j, int n, int m, string s1, string s2, vector<vector<int>>&dp) {
    //     if (i >= n || j >= m)
    //         return 0;
    //         if(dp[i][j] != -1)
    //         {
    //             return dp[i][j];
    //         }
    //     if (s1[i] == s2[j]) {
    //         return dp[i][j] =1 + lcs(i + 1, j + 1, n, m, s1, s2,dp);
    //     }
    //     return dp[i][j]=max(lcs(i + 1, j, n, m, s1, s2,dp), lcs(i, j + 1, n, m, s1, s2,dp));
    // }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==s1[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};