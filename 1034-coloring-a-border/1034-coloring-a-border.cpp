class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {

        int n = grid.size();
        int m = grid[0].size();

        int org = grid[row][col];

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> border;

        q.push({row, col});
        visited[row][col] = true;

        while (!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            bool isBorder = false;

            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                isBorder = true;
            }

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {

                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    continue;
                }

                if (grid[ni][nj] != org) {
                    isBorder = true;
                } else if (!visited[ni][nj]) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }

            if (isBorder) {
                border.push_back({i, j});
            }
        }

        for (auto& x : border) {
            grid[x.first][x.second] = color;
        }

        return grid;
    }
};