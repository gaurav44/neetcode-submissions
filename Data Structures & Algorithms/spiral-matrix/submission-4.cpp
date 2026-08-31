class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = cols - 1;
        int bottom = 0;
        int top = rows - 1;

        vector<int> res;

        while(true) {
            
            // go right
            for(int l = left; l <= right; l++) {
                res.push_back(matrix[bottom][l]);
            }
            bottom++;
            if(bottom > top) break;

            // go bottom
            for(int b = bottom; b <= top; b++) {
                res.push_back(matrix[b][right]);
            }
            right--;
            if(right < left) break;

            // go left
            for(int r = right; r >= left; r--) {
                res.push_back(matrix[top][r]);
            }
            top--;
            if(top < bottom) break;

            // go up
            for(int t = top; t >= bottom; t--) {
                res.push_back(matrix[t][left]);
            }
            left++;
            if(left > right) break;
        }

        return res;
        
    }
};
