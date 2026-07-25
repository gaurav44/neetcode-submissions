class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int curMax = 1, curMin = 1;
        int res = 0;
        
        for(const auto num: nums) {
            int temp = curMax;
            curMax = max({num, num * curMax, num * curMin});
            curMin = min({num, num * temp, num * curMin});
            res = max(curMax, res);
        }    
        return res;
    }
};