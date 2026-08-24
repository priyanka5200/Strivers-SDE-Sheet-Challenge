class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int i = 1;
        while(i<strs.size())
        {
            string cur = strs[i];
            string temp = "";

            for(int j=0; j<ans.size(); j++)
            {
                if(ans[j] == cur[j])
                {
                    temp += ans[j];
                }
                else
                {
                    break;
                }
            }
            ans = temp;
            i++;
        }
        return ans;
        
    }
};