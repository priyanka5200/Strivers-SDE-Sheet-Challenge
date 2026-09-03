class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int d) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] + d - 1) / d;
        }
        return cnt <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};