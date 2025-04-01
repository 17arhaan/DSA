class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size(), candidate = nums[0], count = 1;
            for (int i = 1; i < n; i++) {
                if (nums[i] == candidate) count++;
                else count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
            int total = 0;
            for (int x : nums)
                if (x == candidate) total++;
            int prefix = 0;
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == candidate) prefix++;
                if (prefix * 2 > (i + 1) && (total - prefix) * 2 > (n - i - 1))
                    return i;
            }
            return -1;
        }
    };
    