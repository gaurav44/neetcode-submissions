class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();

        if (n == 1)
            return 0;

        vector<int> dp(n, n);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; --i) {
            int farthest = min(n - 1, i + nums[i]);

            for (int next = i + 1; next <= farthest; ++next) {
                dp[i] = min(dp[i], 1 + dp[next]);
            }
        }

        return dp[0];
    }
};