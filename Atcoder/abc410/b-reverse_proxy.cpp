#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,q;
	cin >> n >> q;

	vector<int> box(n,0),ans;


	int x;
	for(int i=0;i<q;i++){
		cin >> x;
		if(x != 0){
			ans.push_back(x);
			box[x-1] ++;
		}else{
			int idx = 0;
			for(int i=1;i<n;i++){
				if(box[i] < box[idx]) idx = i;
			}
			box[idx] ++;
			ans.push_back(idx+1);
		}
	}

	for(auto g: ans)
		cout  << g << " ";





	return 0;
}
