class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> res;
        string curr;

        unordered_map<char, vector<string>> mp {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q","r","s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
            };

        auto dfs = [&](auto&& self, int di) {
            if(di == digits.size()) {
                res.push_back(curr);
                return;
            }

            for (const string& letter : mp[digits[di]]) {
                curr.push_back(letter[0]);   // choose
                self(self, di + 1);         // explore next digit
                curr.pop_back();            // undo
            }
        };

        if(digits.empty()) return {};
        dfs(dfs, 0);
        return res;
    }
};
