class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp; // num, count;

        for(const auto num: nums) {
            mp[num]++;
        }

        vector<pair<int, int>> inter; 
        for(const auto [key, val]: mp) {
            inter.push_back({key, val});
        }
        
        sort(inter.begin(), inter.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> res;

        for(int i = 0; i < k; i++) {
            res.push_back(inter.at(i).first);
        }

        return res;
    }
};
