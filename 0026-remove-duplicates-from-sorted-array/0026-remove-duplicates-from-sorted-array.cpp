class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j = 1;
        if (nums.size()<=1){
            return nums.size();
        }
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] != nums[i+1]){
                nums[j++] = nums[i+1];
                
            }
        }
        return j;
        
    }
};
