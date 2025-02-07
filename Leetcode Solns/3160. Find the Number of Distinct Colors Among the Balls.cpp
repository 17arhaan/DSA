class Solution {
public:
    vector<int> queryResults(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0);
        unordered_set<int> distinctColors;
        vector<int> result;
        
        for (auto& q : queries) {
            int index = q[0], color = q[1];
            if (colors[index] != 0) distinctColors.erase(colors[index]);
            colors[index] = color;
            distinctColors.insert(color);
            result.push_back(distinctColors.size());
        }
        
        return result;
    }
};