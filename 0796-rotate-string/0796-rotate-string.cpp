class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        s = s + s;

        for (int i = 0; i < goal.size(); i++) {

            string str = s.substr(i, goal.size());
            if (str == goal) {
                return true;
            }
        }
        return false;
    }
};