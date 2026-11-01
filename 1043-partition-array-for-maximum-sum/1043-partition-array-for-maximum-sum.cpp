class Solution {
public:
    int f(int ind, int n, vector<int>& arr, int k, vector<int>& dp) {
        if (ind == n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int len = 0;
        int maxAns = INT_MIN;
        int maxi = INT_MIN;

        for (int i = ind; i < min(n, ind + k); i++) {
            len++;
            maxi = max(maxi, arr[i]);
            int sum = len * maxi + f(i + 1, n, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, arr, k, dp);
    }
};