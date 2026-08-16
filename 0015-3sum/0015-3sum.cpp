class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        int n = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;

           
            int lo = i+1;
            int hi = n-1;

            while(lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if(sum ==0)
                {
                    vector<int>temp = {nums[i] ,nums[lo], nums[hi]};
                    ans.push_back(temp);
                    lo++;
                    hi--;

                    while(lo < hi && nums[lo]==nums[lo-1])lo++;
                     while(lo < hi && nums[hi]==nums[hi+1])hi--;

                }
                else if(sum > 0)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }
        return ans;

        
    }
};