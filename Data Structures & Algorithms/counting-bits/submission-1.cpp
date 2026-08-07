class Solution {
private:
    int countOne(int n) {
        int count = 0;
        for(int i = 0; i < 11; i++) {
            if((n >> i) & 1) count++;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);

        for(int i = 0; i <= n; i++) {
            res.at(i) = countOne(i);
        }
        return res;
    }
};
