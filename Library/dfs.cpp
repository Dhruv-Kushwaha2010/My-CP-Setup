    vector<bool> vis(n);
    vector<int> par(n), dep(n);
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = true;
        for (auto y : adj[x]) {
            if (!vis[y]) {
                par[y] = x;
                dep[y] = dep[x] + 1;
                self(self, y);
            }
        }
    };
