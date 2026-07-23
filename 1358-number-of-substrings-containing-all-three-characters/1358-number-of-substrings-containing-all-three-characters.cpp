class Solution {
public:
    int numberOfSubstrings(string s) {
        int mp[3]= {0,0,0};
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<s.size())
        {
            mp[s[j]-'a']++;

            while(mp[0]>0 && mp[1]>0 && mp[2]>0)
            {
                mp[s[i]-'a']--;
                 ans += (s.size()-j);
                i++;
            }
           
            j++;
        }
        return ans;
        
    }
};