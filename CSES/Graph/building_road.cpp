#include <bits/stdc++.h>
using namespace std;

int n, m, djset[100005], height[100005];

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        djset[i] = i;
        height[i] = 1;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        while (djset[a] != a) {
            a = djset[a];
        }
        while (djset[b] != b) {
            b = djset[b];
        }
        if (a == b)
            continue;
        if (height[a] > height[b]) {
            djset[b] = a;
        } else if (height[a] == height[b]) {
            djset[b] = a;
            height[a]++;
        } else {
            djset[a] = b;
        }
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (djset[i] == i) {
            v.push_back(i + 1);
        }
    }
    int x = v.size();
    cout << x - 1 << "\n";
    for (int i = 1; i < x; i++) {
        cout << v[0] << " " << v[i] << "\n";
    }

    return 0;
}
