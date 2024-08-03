#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	int a[n];
	int tmp=0,p;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(tmp > a[i]) p=i;
		tmp = a[i];
	}
	for(){

	}

	return 0;
}
