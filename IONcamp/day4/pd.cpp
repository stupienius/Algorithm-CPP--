#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,p;

    cin >> a >> b >> p ;

    int ans = 1;
    while(b > 0){
        if(1 & b){
            ans *= a;
            ans %= p;
        }
        a *= a;
        b >>= 1;
    }

    cout << ans ;


    return 0;
}
