#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,q;
	cin >> n >> q;

	vector<int> a;

	for(int i=0;i<n;i++){
		a.push_back(i+1);
	}

	int k = 0;

	int x,p,r;
	for(int i=0;i<q;i++){
		cin >> x;
		if(x == 1){
			cin >> p >> r;
			a[(k+p-1)%n] = r;
		}else if(x == 2){
			cin >> p;
			cout << a[(k+p-1)%n] << "\n";
		}else if(x == 3){
			cin >> r;
			k += r;
			k %= n;
		}
	}

	return 0;
}
