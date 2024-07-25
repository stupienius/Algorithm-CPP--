#include <bits/stdc++.h>
using namespace std;

int n,p;
int a[26];
int ans = 0;
void solve(int k,int sum){

	if(sum > p) return;
	if(k>=n){    // greater than or equal
		if(sum > ans && sum < p) ans = sum;
		return;
	}
	solve(k+1,sum + a[k]);
	solve(k+1,sum);		
}

int main(){
	
	cin >> n >> p;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	solve(0,0);
	cout << ans ;
	return 0;
}
