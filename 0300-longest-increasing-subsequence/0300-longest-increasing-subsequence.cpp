class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int max = 0;
        int omax = 0;

        for (int i = 0; i < n; i++) {
            max = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (max < dp[j])
                        max = dp[j];
                }
            }
            dp[i] = max + 1;
            if (omax < dp[i]) {
                omax = dp[i];
            }
        }
        return omax;
    }
};