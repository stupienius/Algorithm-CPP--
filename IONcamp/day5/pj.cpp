#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    if(n==2){
        unsigned long long a,b,c,d;
        cin >> a >> b >> c >> d;
        
        if(a != c) cout << -1;
        else if(b > d) cout << -1;
        else if((d-b)%a != 0) cout << -1;
        else cout << (d-b)/a ;
           
    }
    else{
        long long a[n],b[n];
    
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        bool out=0;
        for(int i=0;i<n;i++){
            cin >> b[i];
            if(a[i] > b[i]) out = 1;
        }
        
        vector<long long> t;
        int check;
        int ii;
        if(out) cout << -1;
        else if(a[0] != b[0]) cout << -1;
        else{
            for(int i=0;i<n;i++){
                check = 0;
                ii = i;
                for(auto s:t){
                    check += a[i--]*s;
                }
                i = ii;
                if(( b[i]-check)%a[0] != 0){
                    cout << -1;
                    return 0;
                }else{
                    t.push_back((b[i]-check)/a[0]);
                }
            }
            cout << t[1] ;
        }
    }
    return 0;
}
