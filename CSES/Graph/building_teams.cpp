#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> e[100005];
int visited[100005] = {0};

bool dfs(int x, int color) {
    visited[x] = color;
    int size = e[x].size();
    bool ans = true;
    // for (int i = 0; i < n; i++) {
    //     cout << visited[i];
    // }
    // cout << "\n";
    for (int i = 0; i < size; i++) {
        if (visited[e[x][i]] == color)
            return false;
        else {
            if (!visited[e[x][i]])
                ans = dfs(e[x][i], 3 - color) && ans;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        e[a - 1].push_back(b - 1);
        e[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!dfs(i, 1)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << visited[i] << " ";
    }

    return 0;
}
