class Solution {
public:
    string removeOuterParentheses(string s) {
        string str = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                if (st.size() > 1) {
                    str += '(';
                }

            } else {
                if (st.size() > 1) {
                    str += ')';
                }
                st.pop();
            }
        }
        return str;
    }
};