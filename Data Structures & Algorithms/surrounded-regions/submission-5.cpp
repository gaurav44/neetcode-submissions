class Solution {
public:
    void solve(vector<vector<char>>& board) {

        vector<pair<int,int>> dirs = {{1,0}, {0,1},
                                      {-1,0}, {0,-1}};

        int rows = board.size();
        int cols = board[0].size();

        auto dfs = [&](auto&& self, int r, int c) -> void {
            board[r][c] = '1';
            
            for(const auto dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;


                if(nr >= 0 && nr < rows &&
                   nc >=0 && nc < cols &&
                   board[nr][nc]=='O') {

                    self(self, nr, nc);
                }
            }
        };

        for(int r = 0; r < rows; r++) {

            // 1st col
            if(board[r][0] == 'O') {
                dfs(dfs, r, 0);
            } 

            // last col
            if(board[r][cols-1] == 'O') {
                dfs(dfs, r, cols-1);
            } 
        }

        for(int c = 0; c < cols; c++) {
            
            // 1st row
            if(board[0][c] == 'O') {
                dfs(dfs, 0, c);
            } 

            // last row
            if(board[rows-1][c] == 'O') {
                dfs(dfs, rows-1, c);
            }
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == 'O') board[r][c] = 'X';
            }
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == '1') board[r][c] = 'O';
            }
        }
    }
};
