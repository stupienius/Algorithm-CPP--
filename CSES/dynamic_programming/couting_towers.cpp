#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	long long dp[int(1e6+5)],mod = 1e9 + 7;
	dp[1] = 2;
	dp[2] = 8;

	for(int i=3;i<1e6+2;i++){
		dp[i] = (6*dp[i-1] - 7*dp[i-2] + 10*mod) % mod;
	}
	
	int x;
	for(int i=0;i<t;i++){
		cin >> x;
		cout << dp[x] << '\n';
	}

	return 0;
}
