class Solution {
public:
    bool checkValidString(string s) {

        int leftMax = 0, leftMin = 0;
        
        for(const auto c : s) {
            if (c == '(') {
                leftMax++;
                leftMin++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }

            if(leftMax < 0) return false;

            if(leftMin < 0) leftMin = 0;
        }

        return leftMin == 0;
    }
};
