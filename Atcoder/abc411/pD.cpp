#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int x, k;
    string in, server = "";
    vector<string> a(n, "");
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (x == 1) {
            cin >> k;
            k--;
            a[k] = server;
        } else if (x == 2) {
            cin >> k >> in;
            k--;
            a[k] += in;
        } else if (x == 3) {
            cin >> k;
            k--;
            server = a[k];
        }
    }

    cout << server;

    return 0;
}
