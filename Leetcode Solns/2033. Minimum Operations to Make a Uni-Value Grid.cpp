class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            for (auto &row : grid)
                for (auto &num : row)
                    nums.push_back(num);
            int r = nums[0] % x;
            for (int num : nums)
                if (num % x != r)
                    return -1;
            sort(nums.begin(), nums.end());
            int median = nums[nums.size() / 2];
            long long operations = 0;
            for (int num : nums)
                operations += abs(num - median) / x;
            return operations;
        }
    };
    