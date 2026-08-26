class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());

        auto dfs = [&](auto&& self, int remaining, int i) {
            
            if(remaining == 0) {
                res.push_back(curr);
                return;
            }
            
            if(i >= candidates.size() || remaining < 0) return;


            // choose candidates[i]
            curr.push_back(candidates[i]);
            self(self, remaining - candidates[i], i+1);

            // skip candidates[i] and all next subsequent matching cands
            int j = i+1;
            while(j < candidates.size() && candidates[i] == candidates[j]) j++;
            curr.pop_back();
            self(self, remaining, j);
        };

        dfs(dfs, target, 0);
        return res;
        
    }
};
