class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int lo, int hi) {
        int low = lo, high = hi;
        while (low <= high) {
            int mid = high - (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int mid_index(vector<int>& nums) {

       
        int n = nums.size();
        int start = 0;
        int end = n - 1;
         if(nums[0] <= nums[n-1])
        {
            return 0;
        }

        while (start <= end) {
            int mid = end - (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
                return mid;
            }
            if (nums[mid] <= nums[end]) {
                end = mid - 1;
            } else if (nums[start] <= nums[mid]) {
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int mid = mid_index(nums);
        int n = nums.size();
        int a = binarySearch(nums, target, 0, mid - 1);
        int b = binarySearch(nums, target, mid, n - 1);
        if (a == -1) {
            return b;
        } else {
            return a;
        }
    }
};