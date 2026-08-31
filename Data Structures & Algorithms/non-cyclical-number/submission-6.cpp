class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> s;
        s.insert(n);

        auto extrctAndSqr = [&](int x) {
            int sum = 0;
            do {    
                int digit = x % 10;
                sum += digit * digit;
                x = x / 10;
            } while(x);
            std::cout << sum << "\n";
            return sum;
        };

        while(n != 1) {
            int new_num = extrctAndSqr(n);
            
            if(s.contains(new_num)) {
                return false;
            }
            s.insert(new_num);
            n = new_num;
        }

        return true;
        
    }
};
