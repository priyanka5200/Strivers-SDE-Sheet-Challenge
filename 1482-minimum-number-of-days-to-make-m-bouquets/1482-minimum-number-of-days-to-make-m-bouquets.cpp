class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int minDays) {
        int bouquets = 0;
        int cntFlower = 0;
        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= minDays) {
                cntFlower++;
                if (cntFlower == k) {
                    cntFlower = 0;
                    bouquets++;
                }
            } else {
                cntFlower = 0;
            }
        }
        return (bouquets >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};