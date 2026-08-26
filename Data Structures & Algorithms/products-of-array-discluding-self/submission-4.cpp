class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            prefix.at(i) = nums.at(i-1) * prefix.at(i-1);
        }

        vector<int> res(nums.size(), 1);
        int suffix = 1;
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            res.at(i) = prefix.at(i) * suffix;
            suffix *= nums.at(i);
        }
        return res;
    }
};
