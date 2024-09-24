#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int,int>> a;
  int x,y;

  for(int i=0;i<n;i++){
    cin >> x >> y;
    a.push_back(make_pair(x,y));
  }

  sort(a.begin(),a.end());

  auto [l,r] = a[0];
  int ans = r - l;

  for(int i=1;i<n;i++){
    auto [x,y] = a[i];
    // cout << x << " " << y << " " << ans << '\n';
    if(x <= r){
      if(y > r){
        ans += y - r;
        r = y;
      }
    }else{
      ans += y - x;
      r = y;
    }
  }

  cout << ans ;
  

  return 0;
}
