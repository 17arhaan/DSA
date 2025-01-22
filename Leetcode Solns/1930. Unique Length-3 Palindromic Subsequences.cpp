class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> charBounds;
        unordered_set<string> uniquePalindromes;
        
        for (char c = 'a'; c <= 'z'; ++c) {
            charBounds[c] = {-1, -1};
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (charBounds[s[i]].first == -1) {
                charBounds[s[i]].first = i;
            }
            charBounds[s[i]].second = i;
        }
        
        for (auto& entry : charBounds) {
            char a = entry.first;
            int start = entry.second.first;
            int end = entry.second.second;
            
            if (start < end) {
                unordered_set<char> middleChars;
                for (int i = start + 1; i < end; ++i) {
                    middleChars.insert(s[i]);
                }
                for (char b : middleChars) {
                    uniquePalindromes.insert({a, b, a});
                }
            }
        }
        
        return uniquePalindromes.size();
    }
};
