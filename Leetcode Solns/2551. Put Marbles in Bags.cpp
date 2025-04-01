class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
            if (k == 1) return 0; 
    
            vector<int> pairwiseSums;
            
            for (int i = 0; i < n - 1; i++) {
                pairwiseSums.push_back(weights[i] + weights[i + 1]);
            }
    
            sort(pairwiseSums.begin(), pairwiseSums.end());
    
            long long maxSum = 0, minSum = 0;
            for (int i = 0; i < k - 1; i++) {
                minSum += pairwiseSums[i];                 
                maxSum += pairwiseSums[n - 2 - i];             
            }
    
            return maxSum - minSum;
        }
    };