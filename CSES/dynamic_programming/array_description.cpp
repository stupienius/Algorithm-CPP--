#include <bits/stdc++.h>
#include <ios>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, dp[105] = {0}, tmp[105] = {0};

    cin >> n >> m;

    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            if (x == 0) {
                for (int j = 1; j <= m; j++) {
                    dp[j] = 1;
                }
            } else {
                dp[x] = 1;
            }
        } else {
            if (x == 0) {
                for (int j = 1; j <= m; j++) {
                    tmp[j] = dp[j - 1] + dp[j];
                    tmp[j] %= mod;
                    tmp[j] += dp[j + 1];
                    tmp[j] %= mod;
                }
                for (int j = 1; j <= m; j++) {
                    dp[j] = tmp[j];
                }
            } else {
                dp[x] = dp[x - 1] + dp[x];
                dp[x] %= mod;
                dp[x] += dp[x + 1];
                dp[x] %= mod;
                for (int j = 1; j < x; j++)
                    dp[j] = 0;
                for (int j = x + 1; j <= m; j++)
                    dp[j] = 0;
            }
        }
        // for (int j = 0; j <= m + 1; j++) {
        //     cout << dp[j] << " ";
        // }
        // cout << "\n";
    }

    if (x == 0) {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += dp[i];
            ans %= mod;
        }
        cout << ans;
    } else {
        cout << dp[x];
    }

    return 0;
}
