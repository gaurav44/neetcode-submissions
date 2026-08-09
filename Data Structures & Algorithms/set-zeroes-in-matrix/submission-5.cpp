class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false;
        int r = matrix.size();
        int c = matrix[0].size();

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0; 

                    if(i > 0) matrix[i][0] = 0;
                    else row0 = true;
                } 
            }
        }

        for(int i = 1; i < r; i++) {
           for(int j = 1; j < c; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
           }
        }

        if(matrix[0][0] == 0) {
            for(int i = 0; i < r; i++) {
                matrix[i][0] = 0;
            }
        }

        if(row0) {
            for(int i = 0; i < c; i++) 
                matrix[0][i] = 0;
        }
        
    }
};
