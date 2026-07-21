class Solution {
private:
    int gcd(int a, int b) {
        if (a < b)
            gcd(b, a);
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[nums.size() - 1];
        return gcd(max, min);
    }
};