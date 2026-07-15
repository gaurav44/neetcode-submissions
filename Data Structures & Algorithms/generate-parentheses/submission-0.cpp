class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sub_res = "";
        
        auto backtrack = [&](this auto&& backtrack, int close, int open) -> void
        {
            if(open == n && close == n)
            {
                res.push_back(sub_res);
                return;
            } 

            if(close < open) 
            {
                sub_res += ")";
                backtrack(close + 1, open);
                sub_res.pop_back();
            }
            if(open < n)
            {
                sub_res += "(";
                backtrack(close, open + 1);
                sub_res.pop_back();
            }
            
        };

        backtrack(0, 0);
        return res;
        
    }
};
