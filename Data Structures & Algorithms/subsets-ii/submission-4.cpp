class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        auto dfs = [&](auto&& self, int i) {
            if(i >= nums.size()) {
                res.push_back(curr);
                return;
            }

            //choose nums[i]
            curr.push_back(nums[i]);
            self(self, i+1);

            //skip nums[i] and all next subsequent matching nums[i]
            curr.pop_back();
            int j = i + 1;
            while(j < nums.size() && nums[i] == nums[j]) j++;
            self(self, j);
        };
        dfs(dfs, 0);
        return res;
        
    }
};
