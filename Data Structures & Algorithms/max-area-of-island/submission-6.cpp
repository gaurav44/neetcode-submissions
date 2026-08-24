class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        auto visit = [&](auto&& self, int r, int c) -> int {
            if(grid[r][c] == 0) return 0;

            grid[r][c] = 0;
            
            int curr = 1;

            if(r-1 >= 0) curr += self(self, r-1, c);
            if(r+1 < rows) curr += self(self, r+1, c);
            if(c-1 >= 0) curr += self(self, r, c-1);
            if(c+1 < cols) curr += self(self, r, c+1);

            return curr;
        };

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                maxArea = max(visit(visit, i, j), maxArea);
            }
        }
        return maxArea;
    }
};
