#include <bits/stdc++.h>
#include <ios>
#define int long long
using namespace std;
using ll = long long;

int n, k;
const ll mod = 1e9 + 7;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int now = v[1] - v[0], i = 0;
    // cout << now << "\n";
    while (i + 2 < n && k > now + (v[i + 2] - v[i + 1]) * (i + 2)) {
        if (i + 1 >= n)
            break;
        i++;
        now += (v[i + 1] - v[i]) * (i + 1);
    }
    // cout << now << "\n";

    for (int j = 0; j <= i; j++) {
        v[j] = v[i + 1];
    }

    int z = (k - now) / (i + 2);
    int h = (k - now) % (i + 2);
    for (int j = 0; j <= i + 1; j++) {
        v[j] += z;
    }

    for (int j = 0; j < h; j++) {
        v[j]++;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= v[i] % mod;
        ans %= mod;
    }

    cout << ans;

    return 0;
}
