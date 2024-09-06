#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m,n,k;
  cin >> m >> n >> k;

  set<int> a;
  int input;
  int ans = 0;
  for(int i=0;i<m;i++){
    cin >> input;
    a.insert(input);
  }
  for(int i=0;i<n;i++){
    cin >> input;
    if(a.find(k-input) != a.end()){
      ans ++;
    }
  }
  
  cout << ans;

  return 0;
}
