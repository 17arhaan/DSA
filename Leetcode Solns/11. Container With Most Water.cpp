class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n = height.size() , maxCap = 0;
            int lp = 0;
            int rp = n - 1;
            while(lp < rp){
                int wh = rp - lp;
                int ht = min(height[lp],height[rp]);
                int curr = wh * ht;
                maxCap = max(maxCap,curr);
                // if(lp > rp){
                //     rp--;
                // } else lp++;
                height[lp] > height[rp] ? rp-- : lp++;
            }
            return maxCap;
        }
    };