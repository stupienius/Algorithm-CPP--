#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> a;
	int n;

	cin >> n;
	int input;
	for(int i=0;i<n;i++){
		cin >> input;
		a.insert(input);
	}
	cout << a.size() << '\n';
	for(auto i : a){
		cout << i << ' ';
	}
	return 0;
}
