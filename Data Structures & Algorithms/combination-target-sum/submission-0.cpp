class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, target, cur, 0);

        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) return;

        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], cur, i);
        cur.pop_back();
        backtrack(nums, target, cur, i + 1);
    }
};
