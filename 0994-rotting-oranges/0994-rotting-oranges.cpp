class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();
        int days = 0;
        int cnt = 0;
        int no_of_org = 0;

        queue<pair<int, int>> q;

        int r[4] = {0, -1, 0, 1};
        int c[4] = {1, 0, -1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    no_of_org += 1;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int k = q.size();
            cnt += k;
            while (k--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + r[i];
                    int ny = y + c[i];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            if (!q.empty()) {
                days++;
            }
        }
        // cout<< days <<endl;
        if (cnt == no_of_org) {
            return days;
        }

        return -1;
    }
};