class Solution {
public:
    string largestOddNumber(string num) {
        int ind = -1;
        int n = num.size();

        for (int i = n - 1; i >= 0; i--) {
            if (num[i] % 2 == 0) {
                continue;
            } else {
                ind = i;
                break;
            }
        }
        if (ind != -1) {
            return num.substr(0, ind + 1);
        } else {
            return "";
        }
    }
};