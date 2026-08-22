class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProd(nums.size(), 1);
        vector<int> rightProd(nums.size(), 1);
        vector<int> res(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++) {
            rightProd[i] = rightProd[i - 1] * nums[i - 1];
        }

        for(int i = nums.size() - 2; i >= 0; i--) {
            leftProd[i] = leftProd[i+1] * nums[i+1];
        } 

        for(int i = 0; i < res.size(); i++) {
            res.at(i) = leftProd[i] * rightProd[i];
        }

        return res;

    }
};
