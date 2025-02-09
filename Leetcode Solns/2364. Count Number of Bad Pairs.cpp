class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long n = nums.size();
            unordered_map<long long, long long> freq;
            
            for (int i = 0; i < n; i++) {
                freq[(long long)nums[i] - i]++;
            }
            
            long long goodPairs = 0;
            for (const auto &p : freq) {
                goodPairs += p.second * (p.second - 1LL) / 2;
            }
            
            return n * (n - 1LL) / 2 - goodPairs;
        }
    };