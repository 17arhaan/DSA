class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum + target) % 2 != 0 || (totalSum + target) < 0) {
            return 0;
        }
        int S1 = (totalSum + target) / 2;
        vector<int> dp(S1 + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = S1; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[S1];
    }
};
