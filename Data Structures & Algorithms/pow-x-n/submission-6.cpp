class Solution {
private:
    double helper(double x, long n) {
        if(n == 0) return 1;
        
        double half = helper(x, n / 2);

        return (n % 2 == 0) ? half * half : x * half * half;
    }
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;

        if(n == 0) return 1;

        double res = helper(x, abs(static_cast<long>(n)));

        return n >= 0 ? res : 1 / res;
    }
};
