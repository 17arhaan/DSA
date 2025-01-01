//Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;  
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;  
    }
};
//Optimal Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;

        for (int i = 0; i < n; i++) {
            indexedNums.push_back({nums[i], i});
        }

        sort(indexedNums.begin(), indexedNums.end());

        int i = 0, j = n - 1;
        vector<int> ans;

        while (i < j) {
            int pairsum = indexedNums[i].first + indexedNums[j].first;
            if (pairsum > target) {
                j--;
            } else if (pairsum < target) {
                i++;
            } else {
                ans.push_back(indexedNums[i].second);
                ans.push_back(indexedNums[j].second);
                return ans;
            }
        }

        return ans;
    }
};

