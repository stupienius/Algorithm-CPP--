#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set<int> ans;
	ans.insert(0);

	int x;
	for(int i=0;i<n;i++){
		cin >> x;
		vector<int> ass;
		for(auto r : ans){
			ass.push_back(r+x);
		}
		for(auto r : ass){
			ans.insert(r);
		}
	}

	ans.erase(0);

	cout << ans.size() << '\n';

	for(auto r : ans){
		cout << r << " ";
	}

	return 0;
}
