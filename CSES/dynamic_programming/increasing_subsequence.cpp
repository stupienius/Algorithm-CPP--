#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> dp;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << dp.size();

    return 0;
}
