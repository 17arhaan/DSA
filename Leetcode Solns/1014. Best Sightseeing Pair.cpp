class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxSoFar = values[0]; 
        int maxScore = 0; 

        for (int j = 1; j < values.size(); j++) {
            maxScore = max(maxScore, maxSoFar + values[j] - j);
            maxSoFar = max(maxSoFar, values[j] + j);
        }

        return maxScore;
    }
};
