class Solution {
    unordered_map<int, int> mp;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(mp.contains(target-num)) {
                if(i > mp[target - num])
                    return {mp[target-num], i};
                return {i, mp[target-num]};
            } 
            mp[num] = i;
        }
        return {};
    }
};
