class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k)
    {
        long long int calhour = 0;
        for(int i=0; i<piles.size(); i++)
        {
            calhour += (piles[i] +k-1)/k;
        }
        return (calhour<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       // int min =*min_element(piles.begin(), piles.end());
       int low = 1;
        int high=*max_element(piles.begin(),piles.end());
        int ans;

        while(low <= high)
        {
            int mid  = low + (high - low)/2;
            if(isPossible(piles, h, mid))
            {
                ans  = mid;
                high = mid -1;
            }
            else
            {
                low  = mid +1;
            }
            

        }
        return ans;

        
    }
};