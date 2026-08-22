class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, int> mp; // sorted string, idx in row

        for(auto str : strs) {
            string temp = str;

            sort(temp.begin(), temp.end());
            if(mp.contains(temp)) {
                res.at(mp[temp]).push_back(str);
                continue;
            } 

            mp[temp] = res.size();

            res.push_back({str});
        }
        return res;
    }
};
