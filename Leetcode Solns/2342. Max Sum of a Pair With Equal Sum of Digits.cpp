#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = -1;
        for (int num : nums) {
            int s = 0, tmp = num;
            while (tmp) {
                s += tmp % 10;
                tmp /= 10;
            }
            if (m.find(s) != m.end()) {
                ans = max(ans, m[s] + num);
                m[s] = max(m[s], num);
            } else {
                m[s] = num;
            }
        }
        return ans;
    }
};