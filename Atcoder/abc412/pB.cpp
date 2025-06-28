#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int size = s.length();

    bool flag = true;
    for (int i = 1; i < size; i++) {
        if (s[i] > 64 && s[i] < 91) {
            if (t.find(s[i - 1]) == -1) {
                flag = false;
            }
        }
    }

    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
