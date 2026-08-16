class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                 long long tsum = (long long)target - (nums[i] + nums[j]);
                int lo = j + 1;
                int hi = n - 1;

                while (lo < hi) {
                    if (tsum == nums[lo] + nums[hi]) {
                        vector<int> temp = {nums[i], nums[j], nums[lo],
                                            nums[hi]};
                        ans.push_back(temp);

                        while (lo < hi && nums[lo] == nums[lo + 1])
                            lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1])
                            hi--;

                        lo++;
                        hi--;
                    } else if (tsum < nums[lo] + nums[hi]) {
                        hi--;
                    } else {
                        lo++;
                    }
                }
            }
        }
        return ans;
    }
};