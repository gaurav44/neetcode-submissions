class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        int n = nums.size();
        res.reserve(1<<n);
        subset.reserve(n);

        auto dfs = [&](this auto&& dfs, int i){
            if (i == n)
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
