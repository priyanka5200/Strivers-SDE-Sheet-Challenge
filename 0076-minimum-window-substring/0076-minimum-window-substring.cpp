class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        // Frequency of characters in t
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        int cnt = mp.size();

        int i = 0;
        int j = 0;

        int start_index = -1;
        int ans = INT_MAX;

        while (j < s.size()) {

            // Include s[j]
            if (mp.find(s[j]) != mp.end()) {

                mp[s[j]]--;

                if (mp[s[j]] == 0) {
                    cnt--;
                }
            }

            // Current window contains all required characters
            while (cnt == 0) {

                // First save current valid window
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    start_index = i;
                }

                // Now remove s[i]
                if (mp.find(s[i]) != mp.end()) {

                    mp[s[i]]++;

                    // If it becomes positive,
                    // current window is no longer valid
                    if (mp[s[i]] > 0) {
                        cnt++;
                    }
                }

                i++;
            }

            j++;
        }

        return ans == INT_MAX ? "" : s.substr(start_index, ans);
    }
};