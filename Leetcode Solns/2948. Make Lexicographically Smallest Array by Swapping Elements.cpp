class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++) arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){ return a.first < b.first; });
        vector<int> compId(n);
        int comp = 0;
        compId[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i-1].first <= limit) compId[i] = comp;
            else { comp++; compId[i] = comp; }
        }
        int groups = comp + 1;
        vector<vector<int>> indices(groups), values(groups);
        for (int i = 0; i < n; i++) {
            indices[compId[i]].push_back(arr[i].second);
            values[compId[i]].push_back(arr[i].first);
        }
        vector<int> res(n);
        for (int i = 0; i < groups; i++) {
            sort(indices[i].begin(), indices[i].end());
            for (int j = 0; j < indices[i].size(); j++) {
                res[indices[i][j]] = values[i][j];
            }
        }
        return res;
    }
};