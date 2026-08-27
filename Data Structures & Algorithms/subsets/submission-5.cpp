class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        auto dfs = [&](auto&& self, const int i) -> void {
            if(i >= nums.size()) {
                res.push_back(subset);
                return;
            }

            subset.push_back(nums[i]);
            self(self, i + 1);

            subset.pop_back();
            self(self, i + 1);
        };

        dfs(dfs, 0);

        return res;
        
    }
};
