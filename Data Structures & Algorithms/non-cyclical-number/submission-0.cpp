class Solution {
public:
    bool isHappy(int n) {
        int res = n;
        int sum = 0;
        unordered_map<int, int> mp;
        while(sum != 1) {
            sum = 0;
            while(res != 0) {
                int dig = res % 10;
                sum += dig*dig;
                res /= 10;
            }
            if(!mp.contains(sum)) {
                res = sum;
                mp[sum]++;
            } else return false;
        }
        return true;
    }
};
