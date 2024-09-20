#include <bits/stdc++.h>
using namespace std;

#define N 100000

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int height[N] = {0};
  int parent[N] = {0};
  int deg[N] ={0};
  queue<int> q; 
  int ch,input;
  for(int i=0;i<n;i++){
    cin >> ch;
    deg[i+1] = ch;
    if(ch == 0) q.push(i+1);
    for(int j=0;j<ch;j++){
      cin >> input;
      parent[input] = i+1;
    }
 }
  
  int root,ans=0;
  while(!q.empty()){
    int now = q.front();
    ans += height[now];
    q.pop();
    
    if(parent[now] == 0){
      root = now;
      break;
    }

    int father = parent[now];
    height[father] = max(height[father],height[now]+1);

    if(--deg[father] == 0){
      q.push(father);
    }


  }
  cout << root << '\n' << ans;
}
