class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;

        for(int i = s.size() - 1; i >= 0; i--) {
            for(const auto word : wordDict) {
                if(i + word.size() <= s.size() &&
                   s.substr(i, word.size()) == word) { dp[i] = dp[i+word.size()]; }

                if(dp[i] == 1) break;
            }
        }

        return dp[0];
        
    }
};
