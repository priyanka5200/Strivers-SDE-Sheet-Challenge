class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            min = nums[i];
            max = nums[i];
            for (int j = i + 1; j < n ; j++) {
                if (min > nums[j])
                    min = nums[j];
                if (max < nums[j])
                    max = nums[j];
                ans += (max - min);
            }
        }
        return ans;
    }
};