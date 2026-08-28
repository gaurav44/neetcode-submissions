class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minElapsed = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int freshCount = 0;

        vector<pair<int, int>> dirs {{1,0}, {0,1}, {-1,0}, {0,-1}};

        queue<pair<int,int>> rotten;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 2) rotten.push({r,c});
                if(grid[r][c] == 1) freshCount++;
            }
        }

        while(!rotten.empty() && freshCount > 0) {
            int levelSize = rotten.size();

            for(int l = 0; l < levelSize; l++) {
                auto curr_rot = rotten.front();
                rotten.pop();
                int r = curr_rot.first;
                int c = curr_rot.second;

                for(const auto dir: dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols && 
                       grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        rotten.push({nr,nc});
                    }
                }
            }
            minElapsed++;
        }
        return freshCount == 0 ? minElapsed : -1; 
        
    }
};
