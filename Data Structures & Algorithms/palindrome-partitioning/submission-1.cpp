class Solution {
private:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        auto backtrack = [&](this auto&& backtrack, int start) -> void {
            if (start == s.size()) {
                res.push_back(path);
                return;
            }

            for (int end = start; end < s.size(); ++end) {
                if (!isPalindrome(s, start, end)) continue;

                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1);
                path.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};