class Solution {
    int rows, cols;
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for(int r=0; r < rows; r++) {
            if(board[r][0] == 'O')
                capture(board, r, 0);

            if(board[r][cols - 1] == 'O') 
                capture(board, r, cols - 1);
        }

        for(int c=0; c < cols; c++) {
            if(board[0][c] == 'O')
                capture(board, 0, c);

            if(board[rows-1][c] == 'O')
                capture(board, rows-1, c);
        }

        for(int r=0; r < rows; r++) {
            for(int c=0; c < cols; c++) {
                if(board[r][c] == 'O')
                    board[r][c] = 'X';
                else if(board[r][c] == 'T')
                    board[r][c] = 'O';
            }
        }
    }

private:
    void capture(vector<vector<char>>& board, int r, int c) {
        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') return;

        board[r][c] = 'T';
        capture(board, r-1, c);
        capture(board, r+1, c);
        capture(board, r, c+1);
        capture(board, r, c-1);
    }
};
