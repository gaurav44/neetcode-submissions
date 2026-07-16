class Solution {
    array<pair<int, int>, 4> dir = {pair{1, 0}, pair{0, 1},
                                    pair{-1, 0}, pair{0, -1}};

    void dfs(vector<vector<char>>& board, int i, int j) {
        if(board.at(i).at(j) == 'X' || board.at(i).at(j) == 'T') return;

        board.at(i).at(j) = 'T';

        for(auto const [di,dj] : dir) {
            int ni = i+di;
            int nj = j+dj;

            if(ni < r && ni >= 0 && nj < c && nj >= 0) dfs(board, ni, nj);
        }
    }

    int r;
    int c;
public:
    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();

        for(int i = 0; i < r; i++) {
            //first col
            if(board.at(i).at(0) == 'O') dfs(board, i, 0);

            //last col
            if(board.at(i).at(c-1) == 'O') dfs(board, i, c-1);
        }

        for(int i = 0; i < c; i++) {
            //first row
            if(board.at(0).at(i) == 'O') dfs(board, 0, i);

            //last row
            if(board.at(r-1).at(i) == 'O') dfs(board, r-1, i);
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board.at(i).at(j) == 'O') board.at(i).at(j) = 'X';

                if(board.at(i).at(j) == 'T') board.at(i).at(j) = 'O';
            }
        }
    }
};
