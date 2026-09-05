class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            string strs1 = strs[i];
            string temp = "";
            int j = 0;
            while (j < ans.size()) {
                if (ans[j] != strs1[j]) {
                   break;
                }
                temp += ans[j];
                j++;
            }
            ans = temp;
        }
        return ans;
    }
};