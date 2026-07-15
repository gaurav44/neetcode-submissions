class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub_res;

        sort(candidates.begin(), candidates.end());

        auto backtrack = [&](this auto&& backtrack, int start, int remaining)
        {
            if(remaining == 0)
            {
                res.push_back(sub_res);
                return;
            }

            if(remaining < 0) 
                return;

            for(int i = start; i < candidates.size(); i++) 
            {
                if(i > start && candidates[i] == candidates[i-1]) continue;
                if(candidates[i] > remaining) break;
                sub_res.push_back(candidates[i]);
                backtrack(i+1, remaining - candidates[i]);
                sub_res.pop_back();
            }
        };

        backtrack(0, target);

        return res;
    }
};
