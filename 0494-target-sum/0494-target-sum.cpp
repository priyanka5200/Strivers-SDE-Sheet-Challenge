class Solution {
public:
     int f(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base case for first element
        if (arr[0] == 0) {
            dp[0][0] = 2;   // {} and {0}
        } 
        else {
            dp[0][0] = 1;   // {}

            if (arr[0] <= target) {
                dp[0][arr[0]] = 1;
            }
        }

        for (int ind = 1; ind < n; ind++) {

            for (int tar = 0; tar <= target; tar++) {

                // Don't pick current element
                int not_pick = dp[ind - 1][tar];

                // Pick current element
                int pick = 0;

                if (arr[ind] <= tar) {
                    pick = dp[ind - 1][tar - arr[ind]];
                }

                dp[ind][tar] = pick + not_pick;
            }
        }

        return dp[n - 1][target];
    }
    int findTargetSumWays(vector<int>& arr, int diff) {
        int n = arr.size();
        int totsum = 0;
        for(int i=0; i<n; i++)
        {
            totsum += arr[i];
        }
        if(totsum-diff<0 || (totsum-diff)%2)
        return false;
        
        return f(arr, (totsum-diff)/2);
        
    }
};