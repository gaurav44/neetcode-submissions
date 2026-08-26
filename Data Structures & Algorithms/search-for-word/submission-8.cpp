class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {0,1},
                                      {-1,0}, {0, -1}};

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        auto dfs = [&](auto&& self, int r, int c, int i) {
            if(visited[r][c]) return false;
            if(i >= word.size()) return true;

            

            visited[r][c] = true;

            for(auto const dir: dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   board[nr][nc] == word[i]) {
                    
                    if(self(self, nr, nc, i+1)) {
                        visited[r][c] = false;
                        return true;
                    }
                } 
            }
            visited[r][c] = false;
            return false;
        };

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == word[0] && dfs(dfs, r, c, 1)) return true;
            }
        }
        
        return false;
    }
};
