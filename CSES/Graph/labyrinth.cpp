#include <bits/stdc++.h>
using namespace std;

int m, n, lay[1005][1005] = {0}, decc[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
char input;
pair<int, int> b;
queue<tuple<int, int, string>> q;
string dic = "LRUD";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> input;
            if (input != '#')
                lay[i][j] = 1;
            if (input == 'A')
                q.push({i, j, ""});
            if (input == 'B')
                b = {i, j};
        }
    }

    while (!q.empty()) {
        auto [f, g, h] = q.front();
        q.pop();
        lay[f][g] = 0;
        if (f == b.first && g == b.second) {
            cout << "YES" << "\n" << h.length() << "\n" << h;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            if (lay[f + decc[i][0]][g + decc[i][1]]) {
                q.push({f + decc[i][0], g + decc[i][1], h + dic[i]});
            }
        }
    }

    cout << "NO";

    return 0;
}
