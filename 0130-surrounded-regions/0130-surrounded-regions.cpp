class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board) {
        // board[i][j]= 'b';
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'b';

        dfs(i + 1, j, n, m, board);
        dfs(i - 1, j, n, m, board);
        dfs(i, j + 1, n, m, board);
        dfs(i, j - 1, n, m, board);
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int n = board.size();
        int m = board[0].size();

        for (int j = 0; j < m; j++) {
            int i = 0;
            if (board[i][j] == 'O')
                dfs(i, j, n, m, board);
            i = n - 1;
            if (board[i][j] == 'O')
                dfs(i, j, n, m, board);
        }
        for (int i = 0; i < n; i++) {
            int j = 0;
            if (board[i][j] == 'O')
                dfs(i, j, n, m, board);
            j = m - 1;
            if (board[i][j] == 'O')
                dfs(i, j, n, m, board);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'b') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};