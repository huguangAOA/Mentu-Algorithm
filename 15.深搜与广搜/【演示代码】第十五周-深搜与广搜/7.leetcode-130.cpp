class Solution {
public:
    int n, m;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(int i, int j, vector<vector<char>> &board) {
        board[i][j] = 'o';
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if (x < 0 || x >= n) continue;
            if (y < 0 || y >= m) continue;
            if (board[x][y] != 'O') continue;
            dfs(x, y, board);
        }
        return ;
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'o') board[i][j] = 'O';
            }
        }
        return ;
    }
};