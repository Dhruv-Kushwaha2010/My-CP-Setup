struct DSU {
    vector<int> fa;
    vector<vector<int>> cnt;
    void init(int n) {
        fa.assign(n, -1);
        cnt.assign(n, vector<int>(26));
    }
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0) {
            x = fa[x] = fa[fa[x]];
        }
        return fa[x] >= 0 ? fa[x] : x;
    }
    bool query(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (fa[x] > fa[y]) {
            swap(x, y);
        }
        fa[x] += fa[y];
        for (int i = 0; i < 26; ++i) {
            cnt[x][i] += cnt[y][i];
        }
        fa[y] = x;
        return true;
    }
};
