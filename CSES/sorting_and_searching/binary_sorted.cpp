#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, tar;
    cin >> n;
    cin >> tar;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;
    int mid;

    int ans = -1;
    while (r >= l) {
        mid = (l + r) / 2;
        if (arr[mid] == tar) {
            ans = mid;
        } else if (arr[mid] > tar) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
