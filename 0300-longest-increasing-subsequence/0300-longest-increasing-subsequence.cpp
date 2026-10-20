class Solution {
public:
    // int f(int ind, int prev_ind, int len, vector<int> nums,
    //       vector<vector<int>>& dp) {
    //     if (ind == nums.size())
    //         return 0;
    //     if (dp[ind][prev_ind + 1] != -1)
    //         return dp[ind][prev_ind + 1];
    //     len = 0 + f(ind + 1, prev_ind, len, nums, dp);
    //     if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    //         len = max(len, 1 + f(ind + 1, ind, len, nums, dp));
    //     return dp[ind][prev_ind + 1] = len;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int>next(n + 1, 0) , cur(n+1,0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = 0 + next[prev_ind+1];
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                    len = max(len, 1 + next[ind+1]);

               cur[prev_ind + 1] = len;
            }
            next = cur;
        }
        return next[-1 + 1];
    }
};