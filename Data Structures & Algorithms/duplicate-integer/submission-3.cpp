class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;
        for(const auto num: nums) {
            if(count.contains(num)) return true;

            count[num]++;
        }        

        return false;
    }
};