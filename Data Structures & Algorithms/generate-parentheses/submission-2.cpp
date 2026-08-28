class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;

        auto dfs = [&] (auto&& self, int open, int close) {
            if(close >= n) {
                res.push_back(curr);
                return;
            }

            if(open < n) {
                curr.push_back('(');
                self(self, open+1, close);
                curr.pop_back();
            }

            if(close < open) {
                curr.push_back(')');
                self(self, open, close+1);
                curr.pop_back();
            }
        };
        dfs(dfs, 0, 0);
        return res;
        
    }
};
