class Solution {
private:
   bool visit(vector<vector<char>>& grid, int i, int j) {
    if(grid.at(i).at(j) == '0') return false;
    
    grid.at(i).at(j) = '0';
    if(i+1 < grid.size()) visit(grid, i + 1, j);
    if(i-1 >= 0) visit(grid, i-1, j);
    if(j+1 < grid[0].size()) visit(grid, i, j+1);
    if(j-1 >= 0) visit(grid, i, j-1);
    return true;
   }

public:
    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        int res = 0;

        for(int i = 0; i < r; i++) 
        {
            for(int j = 0; j < c; j++)
            {
                if(visit(grid, i, j)) 
                    res++;
            }
        }
        return res;
    }
};
