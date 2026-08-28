class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        auto dfs = [&] (auto&& self, int i, int remaining) {
            if(remaining == 0) {
                res.push_back(curr);
                return;
            }

            if(remaining < 0 || i == candidates.size()) return;

            // choose candidates[i]
            curr.push_back(candidates[i]);
            self(self, i+1, remaining - candidates[i]);

            // skip candidates[i] and subsequent duplicates
            curr.pop_back();
            int j = i + 1;
            while(j < candidates.size() && candidates[i] == candidates[j]) j++;
            self(self, j, remaining);
        };
        
        dfs(dfs, 0, target);
        return res;
    }
};
