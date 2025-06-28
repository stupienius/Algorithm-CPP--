#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, b;
    cin >> n;

    int now = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> b;
        if (b > x) {
            now++;
        }
    }

    cout << now;

    return 0;
}
