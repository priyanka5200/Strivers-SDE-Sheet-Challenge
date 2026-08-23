class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();

        for(int i = n-1; i>=0; i--)
        {
            if(s[i] == ' ')continue;
            string temp = "";
            while(i>=0 && s[i] != ' ')
            {
                temp += s[i];
                i--;
            }
           // cout<<temp<<endl;
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
        }
        return ans.substr(0, ans.size()-1);
       // return ans;
        
    }
};