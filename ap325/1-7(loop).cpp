#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int a[n];
    int p = 10009;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int tmp;
	int ans = 0;
	for(int i=1;i<(1<<n);i++){   // i should start with 1
		tmp = 1;
		for(int j=0;j<n;j++){   // for each bit
			if( i & (1<<j)){
				tmp = (tmp * a[j]) % p;
			}
		}
		if(tmp ==  1){
			ans ++ ;
		}
	}
	cout << ans ;
 	return 0;
}
