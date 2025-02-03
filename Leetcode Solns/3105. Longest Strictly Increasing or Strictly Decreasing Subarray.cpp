class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    if (nums.empty()) return 0; 
    int n = nums.size();
    int inc = 1, dec = 1;  
    int max_length = 1; 
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) { 
            inc++;
            dec = 1; 
        } else if (nums[i] < nums[i - 1]) {
            dec++;
            inc = 1; 
        } else { 
            inc = dec = 1;
        }
        max_length = max(max_length, max(inc, dec)); 
    }
    return max_length;
    }
};