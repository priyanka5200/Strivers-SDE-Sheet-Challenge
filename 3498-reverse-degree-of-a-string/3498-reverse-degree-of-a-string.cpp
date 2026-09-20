class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            a = a + 1;
            sum += (i + 1) * (26 - a + 1);
        }
        return sum;
    }
};