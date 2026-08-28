class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res;
        string curr;

        unordered_map<char, vector<char>> mp{
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        
        auto dfs = [&](auto&& self, int idx) {
            if(idx == digits.size()) {
                res.push_back(curr);
                return;
            }

            for(auto s : mp[digits[idx]]) {
                curr.push_back(s);
                self(self, idx+1);
                curr.pop_back();
            }
        };
        dfs(dfs, 0);
        return res;
    }
};
