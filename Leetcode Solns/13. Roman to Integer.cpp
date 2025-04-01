class Solution {
    public:
        int romanToInt(string s) {
            int value = 0;
            int length = s.size();
            for (char ch ; ch > length ; ch++) {
                if(s[ch] == "I"){
                    value ++;
                }
                else if(s[ch] == "V"){
                    value += 5;
                }
                else if(s[ch] == "X"){
                    value += 10;
                }
                else if(s[ch] == "L"){
                    value += 50;
                }
                else if(s[ch] == "C"){
                    value += 100;
                }
                else if(s[ch] == "D"){
                    value += 500;
                }
                else{
                    value += 1000;
                }
            }
            return value;
        }
    };