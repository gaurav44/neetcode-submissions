class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRow = false;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(matrix[r][c] == 0) {
                    if(r == 0) {
                        firstRow = true;
                        continue;
                    }
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        
        for(int c = 1; c < cols; c++) {
            for(int r = 1; r < rows; r++) {
                if(matrix[0][c] == 0 || matrix[r][0] == 0) matrix[r][c] = 0;
            }
        }

        if(matrix[0][0] == 0) {
            for(int r = 0; r < rows; r++)
                matrix[r][0] = 0;
        }

        if(firstRow) {
            for(int c = 0; c < cols; c++) 
                matrix[0][c] = 0;
        }   
            
    }
};
