class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        
        auto dfs = [&] (auto&& self, int i) {
            if(i >= nums.size()) {
                res.push_back(subset);
                return;
            }

            // pick nums[i]
            subset.push_back(nums[i]);
            self(self, i + 1);

            //skip nums[i] and subsequent duplicates
            int j = i + 1;
            while(j < nums.size() && nums[i] == nums[j]) j++;
            subset.pop_back();
            self(self, j);
        };

        dfs(dfs, 0);

        return res;
    }
};
