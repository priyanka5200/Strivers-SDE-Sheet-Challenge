class Solution {
public:
   int atmost(vector<int>& nums, int k)
{
    int i=0, j=0;
    int ans=0, sum=0;
    if(k<0) return 0;

    while(j<nums.size())
    {
        sum += nums[j];
        while(sum > k)
        {
            sum = sum -  nums[i];
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    return ans;
}
    int numSubarraysWithSum(vector<int>& nums, int k) {
        //cout<<atmost(nums,k)<<endl;
        //cout<<atmost(nums,k-1)<<endl;
        return atmost(nums,k) - atmost(nums,k-1);
    }
};