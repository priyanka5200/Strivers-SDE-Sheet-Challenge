class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        for (int i = 0; i < s.size(); i++) {

            string str = "";
            if (s[i] == ' ') {
              //  i++;
                continue;
            }
            while (i < s.size() && s[i] != ' ') {
                str += s[i];
                i++;
            }
            st.push(str);
        }
       
        string str1 = "";
        while (!st.empty()) {
            str1 += st.top();
            if (st.size() > 1) {
                str1 += ' ';
            }
            st.pop();
        }
        return str1;
    }
};