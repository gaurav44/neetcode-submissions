class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> s_m;
        unordered_map<char, int> t_m;

        for(const auto elem: s) {
            s_m[elem]++;
        }

        for(const auto elem: t) {
            t_m[elem]++;
        }

        for(const auto [k, v] : s_m) {
            if(!t_m.contains(k) || t_m[k] != v) return false;
        }

        return true;
    }
};
