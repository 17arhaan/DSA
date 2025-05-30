class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& a, vector<int>& b, vector<int>& c) {
        unordered_map<int,int> cnt;
        for (int x : unordered_set<int>(a.begin(), a.end())) cnt[x]++;
        for (int x : unordered_set<int>(b.begin(), b.end())) cnt[x]++;
        for (int x : unordered_set<int>(c.begin(), c.end())) cnt[x]++;
        vector<int> res;
        for (auto& [v, k] : cnt) if (k >= 2) res.push_back(v);
        return res;
    }
};
