class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> count;

        for(const auto &num: nums) {
            if(count.find(num) != count.end()) return true;
            count[num]++;
        }
        return false;
    }
};