#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a.begin(),a.end());

	int k;
	cin >> k;

	if(upper_bound(a.begin(),a.end(),k-1) != a.end()){
		int idx = a.end() - upper_bound(a.begin(),a.end(),k-1);
		cout << idx;
	}else{
		cout << '0';
	}

	return 0;
}
