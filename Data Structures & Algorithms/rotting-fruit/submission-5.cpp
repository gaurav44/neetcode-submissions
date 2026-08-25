class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int count = 0;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 2) q.push({r, c});
                else if(grid[r][c] == 1) count++;
            }
        }   

        vector<pair<int, int>> dirs {{1, 0}, {0, 1}, 
                                     {-1, 0}, {0, -1}};
        int time = 0;
        while(!q.empty() && count > 0) {
            int oranges = q.size();
            
            for(int o = 0; o < oranges; o++) {
                auto [r, c] = q.front();
                q.pop();

                for(const auto dir: dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        count--;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
            
        }

        return count == 0 ? time : -1;

        
    }
};
