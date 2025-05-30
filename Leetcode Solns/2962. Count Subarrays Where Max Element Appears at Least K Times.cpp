class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long result = 0;
        vector<int> positions; 
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxElement) {
                positions.push_back(i);
            }
        }
        if (positions.size() < k) {
            return 0;
        }
        for (int i = k - 1; i < positions.size(); i++) {
            int leftBound = positions[i - (k - 1)];
            int rightPos = positions[i];
            int nextRightPos = (i + 1 < positions.size()) ? positions[i + 1] - 1 : n - 1;
            long long leftCount = leftBound + 1; 
            long long rightCount = nextRightPos - rightPos + 1; 
            
            result += leftCount * rightCount;
        }
        
        return result;
    }
};