class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            if (!words[i].empty() && isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            result.push_back(prefixSum[r + 1] - prefixSum[l]);
        }
        
        return result;
    }
};
