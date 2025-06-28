#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a;

    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        sort(a.begin(), a.end());
        if (a.size() == 0) {
            a.emplace_back(x, x);
            cout << 1 << "\n";
            continue;
        }
        auto it = upper_bound(a.begin(), a.end(), make_pair(x, INT_MAX));
        // cout << (it == a.end());
        if (it == a.begin()) {
            if (x == it->first - 1) {
                it->first--;
            } else {
                a.emplace_back(x, x);
            }
        } else {
            it--;
            int r = it->first, l = it->second;
            // cout << r << " " << l << " " << x << " ";
            if (x > l) {
                if (x == l + 1) {
                    it->second++;
                } else if (it + 1 != a.end() && (it + 1)->first == x + 1) {
                    (it + 1)->first--;
                } else {
                    a.emplace_back(x, x);
                }
            } else if (x == r && r == l) {
                a.erase(it);
            } else if (x == r) {
                it->first++;
            } else if (x == l) {
                it->second--;
            } else {
                a.erase(it);
                a.emplace_back(l, x);
                a.emplace_back(x, r);
            }
        }
        cout << a.size() << "\n";
    }

    return 0;
}
