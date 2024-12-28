class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> window_sums(n - k + 1, 0);
        vector<int> left(n - k + 1, 0), right(n - k + 1, 0);
        vector<int> result(3, -1);

        int curr_sum = 0;
        for (int i = 0; i < k; ++i) {
            curr_sum += nums[i];
        }
        window_sums[0] = curr_sum;

        for (int i = 1; i <= n - k; ++i) {
            curr_sum += nums[i + k - 1] - nums[i - 1];
            window_sums[i] = curr_sum;
        }

        int best = 0;
        for (int i = 0; i < window_sums.size(); ++i) {
            if (window_sums[i] > window_sums[best]) {
                best = i;
            }
            left[i] = best;
        }

        best = window_sums.size() - 1;
        for (int i = window_sums.size() - 1; i >= 0; --i) {
            if (window_sums[i] >= window_sums[best]) {
                best = i;
            }
            right[i] = best;
        }

        int max_sum = 0;
        for (int j = k; j <= n - 2 * k; ++j) {
            int l = left[j - k];
            int r = right[j + k];
            int total = window_sums[l] + window_sums[j] + window_sums[r];
            if (total > max_sum) {
                max_sum = total;
                result = {l, j, r};
            }
        }

        return result;
    }
};
