class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(total_sum % 2 != 0) return false;
        int target = total_sum / 2;

        unordered_set<int> dp;
        dp.insert(0);

        for(int i = nums.size() - 1; i >= 0; i--) {
            unordered_set<int> next_dp;

            for(int t : dp) {
                if(t + nums[i] == target) return true;

                next_dp.insert(t+nums[i]);
                next_dp.insert(t);
            }
            dp = next_dp;
        }

        return dp.contains(target);
    }
};
