class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
            string s = to_string(x);
            int lp = 0, rp = s.size() - 1;
            while(lp < rp) {
                if(s[lp] != s[rp])
                    return false;
                lp++;
                rp--;
            }
            return true;
        }
    };
    