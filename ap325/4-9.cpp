#include <bits/stdc++.h>
using namespace std;

int p[50010],n,k;

bool enough(int len){
  int ans = 1;
  int index = 0;
  int now = p[index];
  while(now + len < p[n-1]){
    ans ++;
    if(ans > k) return false;
    while(p[index] < now + len) index ++;
  }
  return true; 
}

int main(){

  cin >> n >> k;

  int input;
  for(int i=0;i<n;i++){
    cin >> input;
    p[i] = input;
  }

  sort(p,p+n);

  



  return 0;
}
