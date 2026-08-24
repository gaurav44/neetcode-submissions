class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        auto visit = [&](auto&& self, int r, int c) -> bool {
            if(grid[r][c] == '0') return false;

            grid[r][c] = '0';
            if(r-1 >= 0) self(self, r-1, c);
            if(r+1 < rows) self(self, r+1, c);
            if(c-1 >= 0) self(self, r, c-1);
            if(c+1 < cols) self(self, r, c+1);

            return true;
        };

        int res = 0;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(visit(visit, i, j)) res++;
            }
        }

        return res;

        
    }
};
