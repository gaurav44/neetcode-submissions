class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, int> count;
        vector<vector<string>> res;

        for(const auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if(count.contains(tmp)) 
                res.at(count[tmp]).push_back(str);
            else {
                res.push_back({str});
                count[tmp] = res.size() - 1;
            }
                
        }
        return res;        
    }
};
