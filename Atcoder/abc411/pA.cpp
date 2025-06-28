#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;

    int size = s.size();

    if (size >= n)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
