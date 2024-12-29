#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = words[0].size();
        int n = target.size();

        vector<vector<int>> freq(26, vector<int>(m, 0));
        for (const string& word : words) {
            for (int j = 0; j < m; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j > 0) {
                    char c = target[j-1];
                    dp[i][j] += dp[i-1][j-1] * freq[c - 'a'][i-1];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[m][n];
    }
};
