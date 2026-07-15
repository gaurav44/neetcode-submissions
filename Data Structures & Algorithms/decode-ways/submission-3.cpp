class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        if (1 == s.size()) return 1;
       
        int prev1 = 1;
        int prev2 = s[0] == '0' ? 0 : 1;
        // cout << prev1 << " " << prev2 << "\n";
        int res = 0;
        for(int i = 1; i < s.size(); i++) {
            res = 0;
            if (s[i] >= '1') 
            {
                res += prev1;
                cout << s[i] << " " << res << " hello1\n";
            }

            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
            { 
                res += prev2;
                cout <<  s[i-1] << " " << s[i] << " " << res << " hello2\n";
            }

            int temp = prev1;
            prev1 = res;
            prev2 = temp;
        }

        return res;
    }
};
