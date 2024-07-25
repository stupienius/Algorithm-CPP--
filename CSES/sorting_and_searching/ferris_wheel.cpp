#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,x;

	cin >> n >> x;

	int ch[n];

	for(int i=0;i<n;i++){
		cin >> ch[i];
	}	
	
	
	sort(ch,ch + n);
	int j;	
	for(int i=n-1;i>=0;i--){
		j = 0;
		while(ch[i] + ch[j] < x) j++; 
	}

	for(int i : ch){
		cout << i << '\t' ;
	}

	return 0;
}
