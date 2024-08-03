#include <bits/stdc++.h>
using namespace std;

long long power(int a,int b){
    long long ans = 1;
    while(b != 0 ){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

long long read_k_base_number(const string &s, int k) {
	long long val = 0;
	for (auto c : s) {
		val = val * k + (c - '0');
	}
	return val;
}

// 給一個 string s 和 int k，代表 k 進位
// 回傳 s 的 10 進位表達式
// ex: read_k_base_number("101", 2) 的結果是 2^2 + 2^0 = 5
long long error_read_k_base_number(const string &s, int k) {
	long long val = 0;
    int len = sizeof(s) / sizeof(char);
    k = power(k,len-1);
	for (auto c : s) {
		val += (c - '0')*k;
        k /= k;
	}
	return val; 
}

// 將一個 10 進位的數字 val 轉乘 k 進位制
// ex: conver_base(5, 2) 的結果是 "101"
string convert_base(long long val, int k) {
	string s = "";
	while (val) {
		s.push_back(val % k + '0');
		val /= k;
	}
	reverse(s.begin(), s.end());
	return s;
}

// 計算一個數字的位數總和
// ex: sum_of_digits("123") 的結果是 1 + 2 + 3 = 6
int sum_of_digits(const string &num) {
	int sum = 0;
	for (auto c : num) {
		sum += c - '0';
	}
	return sum;
}

int main() {
    int t;  
    cin >> t;
    while ( t-- ) { 
        int a, b;
        string s;
        cin >> a >> b >> s;
        long long val = read_k_base_number(s,a);// 將 s 從 a 進位制，轉成 10 進位制
        //cout << val << '\n';
        string num = convert_base(val,b);// 將 val 從 10 進位制轉成 b 進位制
        //cout << num << '\n';
        int sum = sum_of_digits(num);// 計算 num 每個位數的總和
        cout << sum << '\n';
    }
}
