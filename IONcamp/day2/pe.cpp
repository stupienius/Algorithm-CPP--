#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,x;
    cin >> n >> x;
    long long r[n];
    for(int i=0;i<n;i++){
        cin >> r[i];
    }

    unordered_set<long long> ans;

    long long a,b;
    for(int i=0;i<x;i++){
        cin >> a >> b;
        for(int j=a-1;j<b;j++){
            ans.insert(r[j]);
        }
        cout << ans.size() << '\n';
        ans.clear();
    }

    
    return 0;
}
