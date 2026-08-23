class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> maxh;
        for (auto it : mp) {
            maxh.push({it.second, it.first});
        }

        string str = "";
        while (maxh.size() > 0) {
            int val = maxh.top().first;
            while (val--) {
                str += maxh.top().second;
            }
            maxh.pop();
        }
        return str;
    }
};