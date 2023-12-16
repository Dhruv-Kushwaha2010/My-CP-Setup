    auto lca = [&](int x, int y) -> int {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        for (int i = logn; i >= 0; i--) {
            if (dep[x] - (1 << i) >= dep[y]) {
                x = p[i][x];
            }
        }
        for (int i = logn; i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        if (x != y) {
            x = p[0][x];
        }
        return x;
    };
