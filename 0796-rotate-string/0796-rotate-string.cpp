class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
        {
            return false;
        }
        string str = s+s;
        for(int i=0; i<goal.size(); i++)
        {
            string temp = str.substr(i,goal.size());
            if(temp == goal)
            {
                return true;
            }
        }
        return false;
        
    }
};