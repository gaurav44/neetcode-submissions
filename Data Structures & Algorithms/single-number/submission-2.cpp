class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(const int num: nums) {
            res ^= num;
        }
        return res;
    }
};
