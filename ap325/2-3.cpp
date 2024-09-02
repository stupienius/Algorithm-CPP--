// exponentiation by squaring

#include <bits/stdc++.h>
using namespace std;

long long power(int a ,int b){   //a^b

    long long ans = 1;

    while(b > 0){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }

    return ans;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << power(a,b);
}