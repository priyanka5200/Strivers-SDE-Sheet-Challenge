class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double avg = INT_MAX;
        
        int i=0;
        int n = nums.size();
        int j = n-1;
        while(i<j)
        {
            double sum = (nums[i]+nums[j])/2.0;
            if(avg > sum)
            {
                avg = sum;
            }
            i++;
            j--;
        }
        return avg;
        
    }
};