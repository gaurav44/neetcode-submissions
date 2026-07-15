class Solution {
private:
    queue<pair<int, int>> q;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid.at(i).at(j) == 0) q.push({i,j});
            }
        }    

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if(i+1 < r && grid.at(i+1).at(j) == 2147483647)
            { 
                grid.at(i+1).at(j) = grid.at(i).at(j) + 1;
                q.push({i+1,j});
            }
            if(i-1 >= 0 && grid.at(i-1).at(j) == 2147483647) {
                grid.at(i-1).at(j) = grid.at(i).at(j) + 1;
                q.push({i-1,j});
            }   
            if(j+1 < c && grid.at(i).at(j+1) == 2147483647) 
            {
                grid.at(i).at(j+1) = grid.at(i).at(j) + 1;
                q.push({i,j+1});
            } 
            if(j-1 >= 0 && grid.at(i).at(j-1) == 2147483647) 
            {
                grid.at(i).at(j-1) = grid.at(i).at(j) + 1;
                q.push({i,j-1});
            }
        }
    }
};
