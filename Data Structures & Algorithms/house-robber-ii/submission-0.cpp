class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        if (nums.size() == 2) return max(nums[0], nums[1]);

        //including first, excluding last
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size()-1; i++) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }
        int sol = prev1;

        //excluding first, including last
        prev2 = nums[1];
        prev1 = max(nums[1], nums[2]);
        for(int i = 3; i < nums.size(); i++) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }
        sol = max(sol, prev1);

        return sol;
    } 
};
