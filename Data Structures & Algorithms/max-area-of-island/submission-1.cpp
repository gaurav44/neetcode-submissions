class Solution {
private:
    int visit(vector<vector<int>>& grid, int i, int j) {
        if(grid.at(i).at(j) == 0) return 0;

        grid.at(i).at(j) = 0;
        int res = 1;
        if(i+1 < grid.size()) res += visit(grid, i+1, j);
        if(i-1 >= 0) res += visit(grid, i-1, j);
        if(j+1 < grid[0].size()) res += visit(grid, i, j+1);
        if(j-1 >= 0) res += visit(grid, i, j-1);
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = -1;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res = max(res, visit(grid, i, j));
            }
        }

        return res;
    }
};
