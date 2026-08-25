class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size(); 
        const int land = 2147483647;    

        queue<pair<int, int>> q;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 0) q.push({r, c});
            }
        }  
        vector<array<int,2>> dirs {{1, 0}, {0, 1},
                                    {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto [r,c] = q.front();

            q.pop();

            for(auto dir: dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   grid[nr][nc] == land) {
                    
                    grid[nr][nc] = 1 + grid[r][c];
                    q.push({nr, nc});
                }
            }
        }

        // auto dfs = [&](auto&& self, int r, int c) {
        //     if(grid[r][c] == -1) return;
            
        //     if(r - 1 >= 0) {
        //         grid[r-1][c] = min(grid[r-1][c], 1 + grid[r][c]);
        //         self(self, r-1, c);
        //     }
        //     if(r + 1 < rows) {
        //         grid[r+1][c] = min(grid[r+1][c], 1 + grid[r][c]);
        //         self(self, r+1, c);
        //     } 
        //     if(c-1 >= 0) {
        //         grid[r][c-1] = min(grid[r][c-1], 1 + grid[r][c]);
        //         self(self, r, c-1);
        //     } 
        //     if(c+1 < cols) {
        //         grid[r][c+1] = min(grid[r][c+1], 1 + grid[r][c]);
        //         self(self, r, c+1);
        //     }
        // };

              
    }
};
