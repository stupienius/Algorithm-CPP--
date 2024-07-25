#include <bits/stdc++.h>
using namespace std;

int main(){
	int a = 5;
	int &b = a;
	
	a = 10 ;
	cout << b ;
	return 0;
}
