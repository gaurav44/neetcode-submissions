class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        reverse(matrix.begin(), matrix.end());
        int rows = matrix.size();
        int cols = matrix[0].size();
        // transpose
        for(int r = 0; r < rows; r++) {
            for(int c = r+1; c < cols; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        
    }
};
