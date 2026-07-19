class Solution {
    vector<int> memo;
    
    int decode(const string& s, int i) {
        if(i == s.size()) return 1;

        if(s[i] == '0') return 0;

        if(memo[i] != -1) return memo[i];

        int ways = decode(s, i+1);

        if(i+1 < s.size() && 
          ((s[i] - '0') * 10 + s[i+1] - '0') < 27) {
            ways += decode(s, i+2);
        }
        memo[i] = ways;
        return ways;
    }

public:
    int numDecodings(string s) {
        memo.assign(s.size(), -1);
        return decode(s, 0);
    }
};
