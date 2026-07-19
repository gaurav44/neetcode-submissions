class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[nums.size()-1] = nums[nums.size()-1];
        dp[nums.size()-2] = nums[nums.size()-2];
        for(int i = nums.size() - 3; i >= 0; i--) {
            // if(i==2) cout << nums[i+1] << " " << nums[i] << " " << dp[i+2] << "\n";
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
            // cout << i << " " << dp[i] << "\n";
        }

        return max(dp[0], dp[1]);
    }
};
