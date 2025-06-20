#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long int> weight(n);
	
	ll total = 0;
	for(int i=0;i<n;i++){
		cin >> weight[i];
		total += weight[i];
	}

	ll ans = LLONG_MAX;

	for(ll mask = 0;mask <= (1<<n);mask++){
		ll sum = 0;
		for(int i=0;i<n;i++){
			if(mask & (1<<i)){
				sum += weight[i];
			}
		}
		sum = abs(total - 2*sum);
		ans = min(ans,sum);
	}

	
	cout << ans;

	return 0;
}
