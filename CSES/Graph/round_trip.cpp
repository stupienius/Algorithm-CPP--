#include <bits/stdc++.h>
using namespace std;

vector<int> a[100005];
vector<int> visited(100005, -1);
int ans = -1;
int n, m;

bool dfs(int n) {
    if (visited[n] != -1) {
        ans = n;
        return true;
    }
    for (int i = 0; i < n; i++) {
        cout << visited[i] << " ";
    }
    cout << "\n";
    bool r = false;
    for (auto k : a[n]) {
        visited[k] = n;
        r |= dfs(k);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int b, c;
    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        b--;
        c--;
        a[b].push_back(c);
        a[c].push_back(b);
    }

    visited[0] = -2;
    dfs(0);

    // for (int i = 0; i < n; i++) {
    //     if (visited[i] == -1) {
    //         visited[i] = 1;
    //         dfs(i);
    //     }
    // }

    if (ans != -1) {
        vector<int> p;

        int i = ans;
        while (visited[i] != ans) {
            p.push_back(i);
            i = visited[i];
        }
        p.push_back(ans);
        cout << p.size();
        for (auto r : p) {
            cout << r << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
