class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        vector<int> temp = nums[0];

        for (auto it : nums) {
            if (it[0] <= temp[1]) {
                temp[1] = max(temp[1], it[1]);
            } else {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};