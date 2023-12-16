    const int logn = __lg(n);
    vector p(logn + 1, vector<int>(n, -1));
    vector<int> dep(n);
    auto dfs = [&](auto self, int x) -> void {
        for (int i = 0; (2 << i) <= dep[x]; i++) {
            p[i + 1][x] = p[i][p[i][x]];
        }
        for (auto y : adj[x]) {
            if (y == p[0][x]) {
                continue;
            }
            dep[y] = dep[x] + 1;
            p[0][y] = x;
            self(self, y);
        }
    };

