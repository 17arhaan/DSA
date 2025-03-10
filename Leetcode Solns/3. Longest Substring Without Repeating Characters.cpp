class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> lastIndex(128, -1);
            int start = 0, maxLen = 0;
            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];
                if (lastIndex[ch] >= start) {
                    start = lastIndex[ch] + 1;
                }
                lastIndex[ch] = i;
                maxLen = max(maxLen, i - start + 1);
            }
            return maxLen;
        }
    };
    