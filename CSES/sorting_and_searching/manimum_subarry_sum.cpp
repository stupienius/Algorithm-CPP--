#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cin >> n;

    long long now;
    long long ans;

    long long x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            now = x;
            ans = x;
        } else {
            now = max(x, now + x);
            ans = max(now, ans);
        }
    }

    cout << ans;

    return 0;
}
