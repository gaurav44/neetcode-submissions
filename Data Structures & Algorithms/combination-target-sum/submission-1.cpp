class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sub_res;

        auto backtrack = [&](this auto&& backtrack, int start, int remaining) -> void {
            if (remaining == 0)
            {
                res.push_back(sub_res);
                return;
            }
            else if (remaining < 0)
            {
                return;
            }

            for(int i = start; i < nums.size(); i++) 
            {
                sub_res.push_back(nums[i]);
                backtrack(i, remaining - nums[i]);
                sub_res.pop_back();    
            }

        };

        backtrack(0, target);

        return res;
        
    }
};
