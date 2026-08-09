class Solution {
public:
    bool isHappy(int n) {
        int res = n;
        int sum = 0;
        unordered_set<int> s;
        while(sum != 1) {
            sum = 0;
            while(res != 0) {
                int dig = res % 10;
                sum += dig*dig;
                res /= 10;
            }
            if(!s.contains(sum)) {
                res = sum;
                s.insert(sum);
            } else return false;
        }
        return true;
    }
};
