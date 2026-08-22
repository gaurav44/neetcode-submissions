class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> dir = {{1, 0}, {0, 1}, 
                                     {-1, 0}, {0, -1}};

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        auto dfs = [&](auto&& self, int r, int c, int i) -> bool{
            if(i == word.size()) return true;

            if(r < 0 || r >= board.size() || 
               c < 0 || c >= board[0].size() ||
               word[i] != board[r][c] ||
               visited[r][c]) return false;

            visited[r][c] = true;
            for(const auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                
                if(self(self, nr, nc, i + 1)) {
                    visited[r][c] = false;
                    return true;
                }
            }
            visited[r][c] = false;
            return false;
        };

        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0] && dfs(dfs, i, j, 0)) return true;
            }
        }

        return false;
    }
};
