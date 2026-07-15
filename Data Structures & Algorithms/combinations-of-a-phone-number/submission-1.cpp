class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, vector<char>> mp = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
        };

        vector<string> result = {""};  // seed with empty string

        for (char d : digits) {
            vector<string> temp;
            for (const string& existing : result)       // all combos so far
                for (char c : mp[d])                    // cross with next digit's chars
                    temp.push_back(existing + c);
            result = move(temp);
        }

        return result;
    }
};
