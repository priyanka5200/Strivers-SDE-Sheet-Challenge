class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int mi = INT_MAX;
                int ma = INT_MIN;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] != 0) {
                        mi = min(mi, freq[k]);
                        ma = max(ma, freq[k]);
                    }
                }
                sum += (ma - mi);
            }
        }
        return sum;
    }
};