class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;

        auto dfs = [&] (auto&& self, int i, int remaining) -> void {
            if(remaining == 0) {
                res.push_back(current);
                return;
            }

            if(remaining < 0 || i >= candidates.size()) {
                return;
            }

            // pick candidates[i];
            current.push_back(candidates[i]);
            self(self, i + 1, remaining - candidates[i]);

            //skip candidates[i] and all the subsequent duplicates
            int j = i + 1;
            while(j < candidates.size() && candidates[i] == candidates[j]) j++;
            
            current.pop_back();
            self(self, j, remaining);
        };
        
        dfs(dfs, 0, target);

        return res;
    }
};
