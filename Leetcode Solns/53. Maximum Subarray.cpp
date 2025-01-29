class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; 
        int currSum =0; 
        for(int val : nums){
            currSum += val;
            maxSum = max(currSum , maxSum);
            if (currSum < 0) currSum = 0;
        }    
        return maxSum;
    }
};
