class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int r = grid.size();
        int c = grid[0].size();

        int count_fresh = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid.at(i).at(j) == 2) q.push({i,j});
                if(grid.at(i).at(j) == 1) count_fresh++;
            }
        }
        int res = 0;
        while(!q.empty() && count_fresh > 0) {
            int level_size = q.size();

            for(int l = 0; l < level_size; l++) {
                auto [i,j] = q.front();
                q.pop();

                if(i+1 < r && grid.at(i+1).at(j) == 1) {
                    grid.at(i+1).at(j) = 2;
                    q.push({i+1,j});
                    count_fresh--;
                }
                if(i-1 >= 0 && grid.at(i-1).at(j) == 1) {
                    grid.at(i-1).at(j) = 2;
                    q.push({i-1,j});
                    count_fresh--;
                }
                if(j+1 < c && grid.at(i).at(j+1) == 1) {
                    grid.at(i).at(j+1) = 2;
                    q.push({i, j+1});
                    count_fresh--;
                }
                if(j-1 >= 0 && grid.at(i).at(j-1) == 1) {
                    grid.at(i).at(j-1) = 2;
                    q.push({i,j-1});
                    count_fresh--;
                }
            }
            res++;
        }
        
        return count_fresh == 0 ? res : -1;
    }
};
