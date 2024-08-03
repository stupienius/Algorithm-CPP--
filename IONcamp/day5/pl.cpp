#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod =  998244353;


unsigned long long power(long long a,long long b){
    
    unsigned long long ans=1;
    
    while(b){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    
    return ans;
}

 unsigned long long powerf(unsigned long long a,unsigned long long b){
    
    unsigned long long ans=1;
    
    while(b){
        if(b&1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string in;
    cin >> in;
    
    unsigned long long a = 9;
    
    //cout << power(4,2) << '\n';
    
    cout << powerf(a,power(a,a)) ;
    
    
    return 0;
}
