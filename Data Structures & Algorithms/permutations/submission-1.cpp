class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        auto dfs = [&] (auto&& self) -> void {
            if(curr.size() >= nums.size()) {
                res.push_back(curr);
                return;
            }

            for(int i = 0; i < nums.size(); i++) {
                if(used[i]) continue;

                used[i] = true;
                curr.push_back(nums[i]);

                self(self);

                curr.pop_back();
                used[i] = false;
            }
        };

        dfs(dfs);

        return res;
        
    }
};
