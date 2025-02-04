#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0, current_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                current_sum += nums[i];  // Extend ascending subarray
            } else {
                max_sum = max(max_sum, current_sum);  // Update max sum
                current_sum = nums[i];  // Start new subarray
            }
        }

        return max(max_sum, current_sum);  // Final check
    }
};
