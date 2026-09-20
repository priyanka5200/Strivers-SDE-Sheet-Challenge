class Solution {
public:
    int dfs(int i, int j, int cnt, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
            return 0;
        if (grid[i][j] == 2) {
            if (cnt == -1)
                return 1;
            else
                return 0;
        }
        grid[i][j] = -1;
        cnt--;
        int total =
            dfs(i + 1, j, cnt, m, n, grid) + dfs(i - 1, j, cnt, m, n, grid) +
            dfs(i, j - 1, cnt, m, n, grid) + dfs(i, j + 1, cnt, m, n, grid);
        grid[i][j] = 0;
        cnt++;

        return total;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int row, col;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                }
                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                }
            }
        }
        return dfs(row, col, cnt, m, n, grid);
    }
};