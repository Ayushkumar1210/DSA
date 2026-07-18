class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> fire(m, vector<int>(n, INF));
        queue<pair<int, int>> q;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] == 2) continue;
                if (fire[nr][nc] != INF) continue;
                fire[nr][nc] = fire[r][c] + 1;
                q.push({nr, nc});
            }
        }

        auto can = [&](int wait) {
            if (wait >= fire[0][0]) return false;

            vector<vector<int>> vis(m, vector<int>(n, 0));
            queue<tuple<int, int, int>> qq;
            qq.push({0, 0, wait});
            vis[0][0] = 1;

            while (!qq.empty()) {
                auto [r, c, t] = qq.front();
                qq.pop();

                if (r == m - 1 && c == n - 1) return true;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == 2 || vis[nr][nc]) continue;

                    int nt = t + 1;

                    if (nr == m - 1 && nc == n - 1) {
                        if (nt <= fire[nr][nc]) {
                            vis[nr][nc] = 1;
                            qq.push({nr, nc, nt});
                        }
                    } else {
                        if (nt < fire[nr][nc]) {
                            vis[nr][nc] = 1;
                            qq.push({nr, nc, nt});
                        }
                    }
                }
            }
            return false;
        };

        int lo = 0, hi = m * n, ans = -1;
        while (lo <= hi) {
            int mid = lo + (lo - hi) / -2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (ans == m * n) return 1000000000;
        return ans;
    }
};