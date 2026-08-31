class Solution {
public:
    double myPow(double x, int n)  {
        auto helper = [&](auto&& self, double x, long n) -> double {
            if(n == 0) return 1;

            double half = self(self, x, n / 2);

            return (n % 2 == 0) ? half * half : x * half * half;
        };

        if(x == 0) return 0;
        if(x == 1) return 1;

        double res = helper(helper, x, abs(static_cast<long>(n)));

        return n >= 0 ? res : 1 / res;
        
    }
};
