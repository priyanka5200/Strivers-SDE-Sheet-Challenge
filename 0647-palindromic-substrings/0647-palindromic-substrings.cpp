class Solution {
public:
    bool ispal(string str)
    {
        int left = 0;
        int right = str.size()-1;
        while(left < right)
        {
            if(str[left] != str[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt  =0;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
             string str= "";
            for(int j=i; j<n; j++)
            {
                str += s[j];
                if(ispal(str)){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};