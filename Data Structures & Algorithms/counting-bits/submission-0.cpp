class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i = 0; i <= n; i++) {
            int temp = i;
            int localRes = 0;
            while(temp) {
                temp &= temp - 1;
                localRes++;
            }
            res.push_back(localRes);
        }

        return res;
    }
};
