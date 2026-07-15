#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }
        std::cout << result << "\n";
        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        int i = 0;

        while(i < s.size()) {
            int  j = i;
            while(s[j] != '#') {
                j ++;
            }
            std::string str = s.substr(j+1, std::stoi(s.substr(i,j-i)));
            res.push_back(str);
            i = j + 1 + std::stoi(s.substr(i,j-i));
        }
        return res;
    }
};
