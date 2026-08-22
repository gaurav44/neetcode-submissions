class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> mp; //number, count

        // check per row
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(mp.contains(board[i][j])) {
                    cout << "triggered for row!!! " << i << " " << j << "\n" ;
                    return false;
                } 

                mp[board[i][j]]++;
            }
            mp.clear();
        }
        

        // check per column
        for(int j = 0; j < 9; j++) {
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                if(mp.contains(board[i][j])) {
                    cout << "triggered for col!!!\n";  
                    return false;
                } 

                mp[board[i][j]]++;
            }

            mp.clear();
        }

        for(int b = 0; b < 9; b++) {
            int r_start = b / 3;
            int c_start = b % 3;

            r_start *= 3;
            c_start *= 3;
            int r_end = r_start + 3;
            int c_end = c_start + 3;

            for(int r = r_start; r < r_end; r++) {
                for(int c = c_start; c < c_end; c++) {
                    if(board[r][c] == '.') continue;
                    if (mp.contains(board[r][c])) {
                        return false;
                    } 

                    mp[board[r][c]]++;
                }
            }
            mp.clear();
        }
        return true;
    }
};
