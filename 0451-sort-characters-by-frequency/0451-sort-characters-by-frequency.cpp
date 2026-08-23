class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }
        vector<pair<int, char>> v;
        for (auto it : mp) {
            v.push_back({it.second, it.first});
        }
        sort(v.rbegin(), v.rend());
        string str = "";

        for (auto it : v) {
            int temp = it.first;
            while (temp--) {
                str += it.second;
            }
        }
        return str;
    }
};