class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> cnt(board);
        int dir[8][2] = {
            0, 1, 1, 0,
            0, -1, -1, 0,
            1, 1, -1, -1,
            1, -1, -1, 1
        };
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt[i][j] = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dir[k][0], y = j + dir[k][1];
                    if (x < 0 || x >= n) continue;
                    if (y < 0 || y >= m) continue; 
                    cnt[i][j] += board[x][y];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j]) {
                    board[i][j] = (cnt[i][j] == 2 || cnt[i][j] == 3);
                } else {
                    board[i][j] = (cnt[i][j] == 3);
                }
            }
        }
        return ;
    }
};