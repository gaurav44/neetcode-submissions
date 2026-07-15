class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int, std::greater<int>> res;

        for(const auto& num: nums)
        {
            res[num]++;
        }
        
        std::vector<std::pair<int, int>> vec(res.begin(), res.end());

        std::sort(vec.begin(), vec.end(),
                 [](const auto& a, const auto& b) {
                    return a.second > b.second;
                 });
        
        std::vector<int> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(vec[i].first);
        }


        return result;
    }
};
