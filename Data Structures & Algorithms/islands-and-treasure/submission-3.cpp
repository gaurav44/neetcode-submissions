class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        const int land = 2147483647;

        vector<pair<int, int>> dirs {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 0) q.push({r, c});
            }
        }        

        while(!q.empty()) {
            int levelSize = q.size();

            for(int l = 0; l < levelSize; l++) {
                auto [r, c] = q.front();
                q.pop();

                for(const auto dir: dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols &&
                       grid[nr][nc] == land) {

                        grid[nr][nc] = 1 + grid[r][c];
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};
