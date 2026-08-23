class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        if (nums[0] <= nums[n - 1]) {
            return nums[0];
        }

        while (start <= end) {
            int mid = end - (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
                return nums[mid];
            }
            if (nums[mid] <= nums[end]) {
                end = mid - 1;
            } else if (nums[start] <= nums[mid]) {
                start = mid + 1;
            }
        }
        return -1;
    }
};