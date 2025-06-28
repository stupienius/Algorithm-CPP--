#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r;
    cin >> r;
    while (r--) {

        int n;
        cin >> n;

        ll now, end, x, cnt = 1;
        cin >> now;

        vector<ll> a;
        for (int i = 0; i < n - 2; i++) {
            cin >> x;
            a.push_back(x);
        }

        cin >> end;

        sort(a.begin(), a.end());

        auto it = upper_bound(a.begin(), a.end(), 2 * now);
        while (it != a.begin()) {
            if (2 * now >= end) {
                cnt++;
                break;
            }
            it--;
            if (now == *it)
                break;
            now = *it;
            cnt++;
            it = upper_bound(a.begin(), a.end(), 2 * now);
        }

        if (2 * now >= end) {
            if (cnt == 1)
                cnt++;
            cout << cnt << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
