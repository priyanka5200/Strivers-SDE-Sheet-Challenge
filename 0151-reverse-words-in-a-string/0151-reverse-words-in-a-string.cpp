class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i = 0;

        while (i < s.size()) {
            string str = "";
            if (s[i] == ' ') {
                i++;
                continue;
            }
            while (i < s.size() && s[i] != ' ') {
                str += s[i];
                i++;
            }
            st.push(str);
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            if (st.size() > 1) {
                ans += " ";
            }
            st.pop();
        }
        return ans;
    }
};