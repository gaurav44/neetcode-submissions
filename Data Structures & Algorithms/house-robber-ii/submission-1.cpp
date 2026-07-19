class Solution {
private:
    int robRange(int start, int end, vector<int>& nums) {

        int next = 0;
        int nextNext = 0;

        for(int i = end; i >= start; i--) {
            int current = max(next, nums[i] + nextNext);

            nextNext = next;
            next = current;
        }

        return next;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
    

        return max(robRange(0, n-2, nums), robRange(1, n-1, nums));
    }
};
