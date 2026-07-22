class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        lis.back() = 1;

        for(int i = nums.size() - 1; i >= 0; i--) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] > nums[i])
                {
                    lis[i] = max(lis[i], 1+lis[j]); 
                } 
            }
        }

        return *max_element(lis.begin(), lis.end());
        
    }
};
