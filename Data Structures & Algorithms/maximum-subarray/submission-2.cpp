class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSub = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            if(curSum < 0) curSum = 0;

            curSum += nums[i];
            maxSub = max(maxSub, curSum);
        }

        return maxSub;
    }
};
