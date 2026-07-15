class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        if (nums.size() == 2) return max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp; 
        }

        return prev1;
    }
};
