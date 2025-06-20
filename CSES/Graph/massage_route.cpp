#include <bits/stdc++.h>
using namespace std;

int m, n, visited[100005] = {0};
vector<int> e[100005];
queue<int> q;

int main() {

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int size = e[x].size();
        for (int i = 0; i < size; i++) {
            if (!visited[e[x][i]]) {
                visited[e[x][i]] = x;
                q.push(e[x][i]);
            }
        }
    }

    if (visited[n]) {
        vector<int> ans;
        ans.push_back(n);
        while (n != 1) {
            ans.push_back(visited[n]);
            n = visited[n];
        }
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for (int x : ans) {
            cout << x << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
