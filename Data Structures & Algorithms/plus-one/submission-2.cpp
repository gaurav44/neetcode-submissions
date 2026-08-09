class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] < 9) {
            digits[n-1]++;
            return digits;
        }

        int carry = 1;
        vector<int> res(digits.size());
        for(int i = n - 1; i >= 0; i--) {
            if(i == 0) {
                cout << carry + digits[i] << "\n";
            }
            if(carry + digits[i] > 9) {
                carry = 1;
                res.at(i) = (1 + digits[i]) % 10;
            } else {
                res.at(i) = carry + digits[i];
                carry = 0;
            } 
        }
        if(carry == 1) {
            res.push_back(0);
            for(int i = res.size()-1; i >= 1; i--) {
                res.at(i) = res.at(i-1);
            }
            res.at(0) = 1;
        };
        return res;
    }
};
