class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> last_seen;
        int left = 0;
        int best = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];

            if (last_seen.contains(c)) {
                left = std::max(left, last_seen[c] + 1);
            }

            last_seen[c] = right;

            best = std::max(best, right - left + 1);
        }

        return best;
    }

};
