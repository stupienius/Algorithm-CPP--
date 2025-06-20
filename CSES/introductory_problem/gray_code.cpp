#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int l = 0, r = n;
	int i = 0,cr = 1,now = 0,change = 0;
	while(l != r){
		cout << bitset<3>(now) << '\n';
		now ^= cr;
		if(now == l){
			change = !change;
			l ++;
		}
		if(now = r){
			change = !change;
			r --;
		}
		if(change){
			cr >>= 1;
		}else{
			cr <<= 1;
		}
	}


	return 0;
}
