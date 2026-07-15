class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0;

        int res = 0;
        int maxf = 0;
        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            count[c]++;
            maxf = max(maxf, count[c]);

            while((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
