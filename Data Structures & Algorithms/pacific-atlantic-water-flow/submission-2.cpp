class Solution {
private:
    array<pair<int, int>, 4> directions = {pair{1, 0}, pair{-1, 0},
                                           pair{0, 1}, pair{0, -1}};

    void dfs(vector<vector<int>>& allowed,
             const vector<vector<int>>& heights,
             int i, int j)
    {
        if(allowed.at(i).at(j) == 1) return;

        allowed.at(i).at(j) = 1;

        for(auto const [di,dj]: directions) {
            int ni = i + di;
            int nj = j + dj;

            if(ni < r && ni >=0 && nj < c && nj >= 0 &&
              heights.at(ni).at(nj) >= heights.at(i).at(j))
              dfs(allowed, heights, ni, nj);
        }
    }

    int r = 0;
    int c = 0;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size(); 

        vector<vector<int>> pac(r, vector<int>(c, 0));
        vector<vector<int>> atl(r, vector<int>(c, 0));

        for(int i = 0; i < r; i++) {
            // pac.at(i).at(0) = 1;
            // atl.at(i).at(c-1) = 1;
            dfs(pac, heights, i, 0);
            dfs(atl, heights, i, c-1);
        }

        for(int i = 0; i < c; i++) {
            // pac.at(0).at(i) = 1;
            // atl.at(r-1).at(i) = 1;
            dfs(pac, heights, 0, i);
            dfs(atl, heights, r-1, i);
        }

        vector<vector<int>> res;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(pac.at(i).at(j) == 1 && atl.at(i).at(j) == 1) 
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
