#include <ranges>
#include <algorithm>

class Solution {
private:
    bool isPalindrome(const string& s) {
        return ranges::equal(s, s | views::reverse);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub_res;

        auto backtrack = [&](this auto&& backtrack, int start) -> void {
            if (start == s.length()) {
                res.push_back(sub_res);
                return;
            }

            for (int i = start; i < s.length(); i++) {
                string candidate = s.substr(start, i - start + 1);

                if (isPalindrome(candidate)) {
                    sub_res.push_back(candidate);
                    backtrack(i + 1);
                    sub_res.pop_back();
                }
            }
        };

        backtrack(0);
        return res;
    }
};