#include <bits/stdc++.h>
using namespace std;

long long int power(int a,int n){
    long long int ans = 1;

    while (n > 0){
        if(n%2 == 1){
            ans *= a;
        }
        a = a*a;
        n >>= 1;
    }

    return ans;
}

int main(){


    int n,a,b;

    cin >> n >> a >> b;

    if(n%2==0){
        cout << "不能";
    }else{
        cout << "能" << '\n';
        cout << power(a,n) + power(b,n);
    }

    return 0;
}
