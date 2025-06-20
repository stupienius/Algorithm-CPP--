#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;

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
    
    int x,y,cnt = 2,i,chg1,chg2;
    for(int k=0;k<m;k++){
        cin >> x >> y;
        x --;
        y --;
        i = 0;
        while(cnt){
            if(V[i].second == x){
                chg1 = i;
                cnt -- ;
            }
            if(V[i].second == y){
                chg2 = i;
                cnt --;
            }
            i++;
        }

        auto [tmp1,tmp2] = V[chg1];
        V[chg1] = V[chg2];
        V[chg2] = {tmp1,tmp2};

        if(chg1 != 0 && V[chg1].first < V[chg1 - 1].first) ans ++;
        if(chg1 != n-1 && V[chg1].first > V[chg1 + 1].first) ans ++;
        if(chg2 != 0 && V[chg2].first < V[chg2 - 1].first && chg2-1 != chg1) ans ++;
        if(chg2 != n-1 && V[chg2].first > V[chg2 + 1].first && chg2+1 != chg1) ans ++;

        cout << ans;
    }



    return 0;
}
