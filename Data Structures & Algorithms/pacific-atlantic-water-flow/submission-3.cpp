class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<int>> res;

        vector<pair<int, int>> dirs {{1,0}, {0,1}, {-1,0}, {0, -1}};

        auto dfs = [&](auto&& self, int r, int c, vector<vector<bool>>& visited) {
            if(visited[r][c]) return;

            visited[r][c] = true;

            for(auto const dir: dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   heights[nr][nc] >= heights[r][c]) {
                    self(self, nr, nc, visited);
                }
            }
        };

        for(int i = 0; i < rows; i++) {
            dfs(dfs, i, 0, pacific);
            dfs(dfs, i, cols - 1, atlantic);
        }

        for(int i = 0; i < cols; i++) {
            dfs(dfs, 0, i, pacific);
            dfs(dfs, rows-1, i, atlantic);
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        
        return res;
    }
};
