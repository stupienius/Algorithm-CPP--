#include <bits/stdc++.h>
using namespace std;

int n, x;
map<int, int> m;

int main() {

    cin >> n >> x;

    int r;
    for (int i = 0; i < n; i++) {
        cin >> r;
        if (m.find(x - r) != m.end()) {
            cout << i + 1 << " " << m[x - r];
            return 0;
        } else {
            m[r] = i + 1;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
