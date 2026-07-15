class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> res;

        for(auto& str: strs)
        {
            auto sorted_str = str; //make a copy first
            std::sort(sorted_str.begin(), sorted_str.end());
            res[sorted_str].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for(auto &pair: res)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
