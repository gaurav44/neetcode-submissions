class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        auto dfs = [&](this auto&& dfs, int i){
            if (i == nums.size())
            {
                res.push_back(subset);
                return;
            }

            subset.push_back(nums[i]);
            dfs(i+1);

            subset.pop_back();
            dfs(i+1);    
        };

        dfs(0);

        return res;
    }
};
