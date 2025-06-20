#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<int,int>> V(n);
    
    int a;
    for(int i=0;i<n;i++){
        cin >> a; 
        V[i] = {a,i};
    }

    sort(V.begin(),V.end());

    int ans = 1;
    for(int i=0;i<n-1;i++){
        if(V[i].second > V[i+1].second){
            ans ++;
        }
    }

    cout << ans;


    return 0;
}
