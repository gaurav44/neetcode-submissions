class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.empty() && t.empty()) return true;

        if(s.size() != t.size()) return false;

        int n = s.size();

        std::unordered_map<char, int> count_s;
        std::unordered_map<char, int> count_t;

        for(int i = 0; i < n; i++) 
        {
            count_s[s.at(i)]++;
            count_t[t.at(i)]++;
        }

        for(auto const &[key, val]: count_s)
        {
            if(val != count_t[key]) return false;
        }
        return true;
    }
};
