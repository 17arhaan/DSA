class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n + 1, 0);
            for (int i = n - 1; i >= 0; --i) {
                int nextIndex = i + questions[i][1] + 1;
                long long solve = questions[i][0] + (nextIndex < n ? dp[nextIndex] : 0);
                long long skip = dp[i + 1];
                dp[i] = max(solve, skip);
            }
            
            return dp[0];
        }
    };
    