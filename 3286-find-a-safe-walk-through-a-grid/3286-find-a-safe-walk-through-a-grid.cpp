class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> vis;
    bool ok = false;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int i, int j, int health, vector<vector<int>>& grid) {
        if (health <= 0 || ok) {
            return;
        }

        if (i == m - 1 && j == n - 1) {
            ok = true;
            return;
        }

        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n || vis[ni][nj]) {
                continue;
            }

            int nh = health - grid[ni][nj];

            if (nh <= dp[ni][nj]) {
                continue;
            }

            dp[ni][nj] = nh;
            dfs(ni, nj, nh, grid);
        }

        vis[i][j] = 0;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        health -= grid[0][0];

        if (health <= 0) {
            return false;
        }

        dp.assign(m, vector<int>(n, -1));
        vis.assign(m, vector<int>(n, 0));

        dp[0][0] = health;

        dfs(0, 0, health, grid);

        return ok;
    }
};