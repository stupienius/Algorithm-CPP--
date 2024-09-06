//modular multiplicative inverse
#include <bits/stdc++.h>
using namespace std;

int quick_power(int a,int b,int p){
  int ans = 1;
  while(b!=0){
    if(b&1){
      ans *= a;
      ans %= p;
    }
    a *= a;
    a %= p;
    b >>= 1;
  }
  return ans;
}

int main(){

  int n,p;
  cin >> n >> p;

  int input;
  for(int i=0;i<n;i++){
    cin >> input;
    input = quick_power(input,p-2,p) % p;
    cout << input << " ";
  }

  return 0;
}
