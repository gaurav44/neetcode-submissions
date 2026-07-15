class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub_res;

        sort(nums.begin(), nums.end());

        auto backtrack = [&](this auto&& backtrack, int start) -> void
        {
            res.push_back(sub_res);
         
            for(int i = start; i < nums.size(); i++) 
            {
                if(i > start && nums[i] == nums[i-1]) continue;
                sub_res.push_back(nums[i]);
                backtrack(i+1);
                sub_res.pop_back();
            }
        };

        backtrack(0);

        return res;
    }
};
