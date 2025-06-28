#include <bits/stdc++.h>
using namespace std;

vector<int> e[8], visited(8, 0);

int dfs(int n) {
    visited[n] = 1;
    int ans = 0;
    for (auto x : e[n]) {
        if (!visited[x]) {
            ans = max(ans, dfs(x));
        }
    }
    return ans + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int r = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cnt++;
            r += dfs(i);
        }
    }

    cout << (m - r) + (cnt == 1 ? 0 : cnt);

    return 0;
}
