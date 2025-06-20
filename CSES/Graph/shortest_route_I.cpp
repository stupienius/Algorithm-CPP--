// dijkstra algorithm
// 1: find the shortest e now
// 2: determine the node
// 3: relax

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<ll> dis(n, inf);
    vector<pair<int, int>> e[m];

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        a--;
        b--;
        e[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<ll>> qp;

    qp.emplace(0, 0);

    while (!qp.empty()) {
        auto [node, desti] = qp.top();
        qp.pop();
        if (dis[node] <= desti)
            continue;
        dis[node] = desti;
        for (auto [r, s] : e[node]) {
            if (desti + s < dis[r])
                continue;
            qp.emplace(r, desti + s);
        }
    }

    return 0;
}
