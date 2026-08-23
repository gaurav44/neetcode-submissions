class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> curr;

        auto isPalindrome = [](string s) -> bool {
            string temp = s;
            reverse(temp.begin(), temp.end());

            return s == temp;
        };

        auto dfs = [&](auto&& self, int start) {
            if(start == s.size()) {
                res.push_back(curr);
                return;
            }

            for(int end = start; end < s.size(); end++) {
                
                string piece = s.substr(start, end - start + 1);

                if(!isPalindrome(piece)) continue;

                curr.push_back(piece);
                self(self, end+1);
                curr.pop_back();
            }
        };

        dfs(dfs, 0);

        return res;
        
    }
};
