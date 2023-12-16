    auto bfs = [&](int i) {
        vector<int> dis(n, -1);
        queue<int> q;
        q.push(i);
        dis[i] = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto y : adj[x]) {
                if (dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
        return dis;
    };
