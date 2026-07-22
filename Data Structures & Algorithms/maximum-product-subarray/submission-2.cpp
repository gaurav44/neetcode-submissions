class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());

        int curMax = 1;
        int curMin = 1;

        for(const auto num: nums) {
            int temp = curMax * num;
            curMax = max({curMax * num, curMin * num, num});
            curMin = min({temp, curMin * num, num});
            res = max(res, curMax);
        }
        
        return res;
    }
};
