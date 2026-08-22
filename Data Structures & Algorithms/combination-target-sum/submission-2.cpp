class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        vector<int> current;

        auto dfs = [&] (auto&& self, int i, int remaining) -> void{
            if(remaining == 0) {
                res.push_back(current);
                return;
            }

            if(remaining < 0 || i >= nums.size()) return;

            // take nums[i]
            current.push_back(nums[i]);
            self(self, i, remaining - nums[i]);

            // skip nums[i]
            current.pop_back();
            self(self, i + 1, remaining);
        };

        dfs(dfs, 0, target);

        return res;
        
    }
};
