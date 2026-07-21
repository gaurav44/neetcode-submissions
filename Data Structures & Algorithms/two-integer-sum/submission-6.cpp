class Solution {
    unordered_map<int, int> mp;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            if(mp.contains(target-num)) {
                // if(i > mp[target - num])
                    return {mp[target-num], i};
                // return {i, mp[target-num]};
            } 
            mp[nums[i]] = i;
        }
        return {};
    }
};
