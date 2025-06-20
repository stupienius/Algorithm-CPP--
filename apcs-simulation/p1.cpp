#include <bits/stdc++.h>
#include <ios>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll u;
    int n;

    cin >> u >> n;

    int k = log(u) / log(2);

    int x;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        k = log(u) / log(2);
        cin >> x;
        while (k / 2 >= 1) {
            // cout << bitset<8>(x) << " " << k / 2 << " " << (x >> (k / 2)) << "\n";
            ans.push_back(x >> (k / 2));
            x -= x >> (k / 2) << (k / 2);
            k -= k / 2 + (k % 2 == 0 ? 0 : 1);
            // cout << k << "\n";﻿
        }
        ans.push_back(x);
        for (int d : ans)
            cout << d << " ";
        cout << "\n";
        ans.clear();
    }
}
