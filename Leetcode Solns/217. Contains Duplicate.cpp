class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> dupli;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(dupli.find(nums[i]) == dupli.end()) dupli[nums[i]]++;
            else return true;
        }
        return false;
    }
};