class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        for(int i = nums.size() - 3; i >= 0; i--) {
            int next_max = nums[i+2];
            for(int j = i + 2; j < nums.size(); j++) {
                if(nums[j] > next_max)
                {
                    next_max = nums[j];
                    break;
                } 
            }
            nums[i] = nums[i] + next_max;
        }

        return max(nums[0], nums[1]);
    }
};
