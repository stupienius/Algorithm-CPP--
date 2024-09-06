//subset product
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,p;
  cin >> n >> p;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i]; 
  }
  
  map<int,int> M1; //product -> count

  M1[a[0]] = 1;
  for(int i=1;i<n;i++){
    map<int,int> M2(M1);
    for(auto x : M1){
      int t = (x.first * a[i]) % p;
      M2[t] = (M2[t] + x.second) % p;
    }
    M2[a[i]] = (M2[a[i]] + 1) % p ;
    M1.swap(M2);
  }
  
  cout << M1[1];

  return 0;
}
