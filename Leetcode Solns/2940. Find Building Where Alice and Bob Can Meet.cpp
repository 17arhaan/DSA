class Solution {
public:
    using int2 = pair<int, int>;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size(), qz=queries.size();
        vector<int> ans(qz, -1);
        vector<int2> idx;

        for (int i= 0; i< qz; i++) {
            int& x=queries[i][0], & y=queries[i][1];
            if (x > y) // let x <= y
                swap(x, y);
            if (x == y|| heights[x]<heights[y])
                ans[i] = y;
            else idx.emplace_back(y, i);
        }

        sort(idx.begin(), idx.end(), greater<>());
        vector<int2> stack;

        int j=n-1;
        for (auto [_, i] : idx) {
            int x = queries[i][0];
            int y = queries[i][1];
            for (; j >y; j--) {
                while (!stack.empty() && heights[stack.back().second] < heights[j])
                    stack.pop_back();
                stack.emplace_back(heights[j], j);
            }

            // Check if accessing elements beyond the bounds of stack here
            auto it=upper_bound(stack.rbegin(), stack.rend(), make_pair(heights[x], n));
            ans[i]=(it==stack.rend()) ?-1 : it->second;
        }
        return ans;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();