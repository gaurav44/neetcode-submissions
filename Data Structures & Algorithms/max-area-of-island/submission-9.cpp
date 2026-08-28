class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        vector<pair<int,int>> dirs {{1,0}, {0,1},
                                    {-1,0}, {0,-1}};

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        auto dfs = [&](auto&& self, int r, int c, int& curr, vector<vector<bool>>& visited) {
            if(grid[r][c] == 0 || visited.at(r).at(c)) return;
            curr = curr + 1;
            visited.at(r).at(c) = true;
            for(auto dir: dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nr < rows && 
                   nc >= 0 && nc < cols && 
                   !visited[nr][nc]) {
                    self(self, nr, nc, curr, visited);
                }
            }
            maxArea = max(maxArea, curr);
        };

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                int curr = 0;
                dfs(dfs, r, c, curr, visited);
            }
        }

        return maxArea;
    }
};
