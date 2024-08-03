
#include <bits/stdc++.h>
using namespace std;

int a[200005];
int n,p;

int find(int m){
    int ans = a[m];
    int index = m;
    for(int i=m+1;i<n;i++){
        if(ans - a[i] > i-index){
            ans = a[i];
            index = i;
        }
    }
    return ans + (index-m);
}
int rfind(int m){
    int ans = a[m];
    int index = m;
    for(int i=m-1;i>=0;i--){
        if(ans - a[i] > index - i){
            ans = a[i];
            index = i;
        }
    }
    return ans + (m - index);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> p;
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int cmd;
    int k,x;
    for(int i=0;i<p;i++){
        cin >> cmd;
        if(cmd == 1){
            cin >> k >> x;
            a[k-1] = x;
        }else{
            cin >> k;
            cout << min(find(k-1),rfind(k-1)) << '\n';
        }
    }


    
    return 0;
}
