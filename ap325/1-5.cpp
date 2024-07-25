#include <bits/stdc++.h>
using namespace std;

string s;
int i = -1;

long long sovle(int n){
	i++;
	if(s[i] == '2'){
		return sovle(n/2) + sovle(n/2) + sovle(n/2) + sovle(n/2);	
	}	
	if(s[i] == '1'){
		return n*n;
	}
	return 0;
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	cin >> s;
	int n;
	cin >> n;	
	
	cout << sovle(n);

	return 0;
}
