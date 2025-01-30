#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor1 ^= nums[i];
            xor2 ^= (i + 1);
        }

        return xor1 ^ xor2;
    }
};