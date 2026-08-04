class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++) {
            if(i > mp[s[i]]) mp[s[i]] = i;
        }

        int size = 0; 
        int end = 0;
        vector<int> output;
        for(int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, mp[s[i]]);
            if(i == end) {
                output.push_back(size);
                size = 0;
            } 
        }

        return output;
    }
};
