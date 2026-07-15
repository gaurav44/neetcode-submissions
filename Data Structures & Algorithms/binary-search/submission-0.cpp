class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = std::ranges::lower_bound(nums, target);

        if(it != nums.end() && *it == target) 
            return it - nums.begin();
        return -1;
    }
};
