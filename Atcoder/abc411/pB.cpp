#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << a[j] - a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
