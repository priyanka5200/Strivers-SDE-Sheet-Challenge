class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v;

        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i]) == mp.end()) {
                v.push_back(arr[i]);
                mp[arr[i]] = 0;
            }
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            mp[v[i]] = i + 1;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};