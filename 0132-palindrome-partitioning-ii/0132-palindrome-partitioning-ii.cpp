class Solution {
public:
    bool isPalindrome(int s, int e, string &str) {
       if(s>=e)return true;
       if(str[s] != str[e])return false;
       return isPalindrome(s+1, e-1, str);
    }
    // int f(int i, int n, string str, vector<int>& dp) {
    //     if (i == n)
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     int mincost = INT_MAX;
    //     for (int j = i; j < n; j++) {
    //         if (isPalindrome(i, j, str)) {
    //             int cost = 1 + f(j + 1, n, str, dp);
    //             mincost = min(mincost, cost);
    //         }
    //     }
    //     return dp[i] = mincost;
//} 
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int mincost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + dp[j + 1];
                mincost = min(mincost, cost);
            }
        }
        dp[i] = mincost;
    }

    return dp[0] - 1;
}
}
;