class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        vector<int> curr;

        auto dfs = [&](auto&& self, int remaining, int i) {
            if(remaining == 0) {
                res.push_back(curr);
                return;
            }

            if(remaining < 0 || i >= nums.size()) return;

            // choose i
            curr.push_back(nums[i]);
            self(self, remaining - nums[i], i);

            // skip i
            curr.pop_back();
            self(self, remaining, i+1);
        };

        dfs(dfs, target, 0);
        return res;
        
    }
};
