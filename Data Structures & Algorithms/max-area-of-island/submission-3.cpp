class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        auto visit = [&](auto&& self, int r, int c, int& curr) -> int {
            if(grid[r][c] == 0) return 0;

            grid[r][c] = 0;
            
            curr++;
            // cout << "r: " << r << " c:" << c << " curr:" << curr << "\n";

            if(r-1 >= 0) self(self, r-1, c, curr);
            if(r+1 < rows) self(self, r+1, c, curr);
            if(c-1 >= 0) self(self, r, c-1, curr);
            if(c+1 < cols) self(self, r, c+1, curr);

            // cout << "Returning curr for r, c " << curr << " " << r << " " << c <<"\n";

            return curr;
        };


        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                // cout << "i: " << i << " j: " << j << " " << " area: " << visit(visit, i, j, 0) << "\n";
                int curr = 0;
                maxArea = max(visit(visit, i, j, curr), maxArea);
            }
        }
        return maxArea;
    }
};
