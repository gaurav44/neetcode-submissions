class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int target = sum / 2;

        unordered_set<int> dp;
        dp.insert(0);

        for(const auto num : nums) {
            unordered_set<int> next_dp;
            for(const auto t : dp) {
                if(num + t == target) return true;

                next_dp.insert(num + t);
                next_dp.insert(t);
            }
            dp = next_dp;
        }
        
        return dp.contains(target);
    }
};
