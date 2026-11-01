class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    bool checkPartitioning(string s) {
        for (auto i = 2; i < s.size(); ++i) {
            if (isPal(s, i, s.size() - 1)) {
                for (auto j = 1; j < i; ++j)
                    if (isPal(s, j, i - 1) && isPal(s, 0, j - 1))
                        return true;
            }
        }
        return false;
    }
};