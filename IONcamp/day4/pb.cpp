#include <iostream>
#include <vector>
using namespace std;

vector<int> Primes(int M) {
    vector<bool> isPrime(M+1,true);
    vector<int> ans;
    for(int i=2;i <= M ;i++){
        if(isPrime[i]){
            ans.push_back(i);
            for(int j=i+i;j<=M;j+=i){
                isPrime[j] = false;
            }
        }
    }

    return ans;
}


int main() {
    // 輸入 n
    int n;
    cin >> n;

    // 找出所有 n 以下的質數。
    // Primes(n) 回傳的 vector 會由小到大包含 1   n 的所有質數
    vector<int> primes = Primes(n); // Primes 的實作可以參見（抄）基礎數論投影片。

    for (int k = 1; k <= n; ++ k) {
        // 當 primes 的 vector 非空
        // 而且 primes 中最大數（最後一個數）乘上 k 的值大於 n 的話就 pop_back
        while (primes.empty() == false && primes.back() * k > n) {
            primes.pop_back();
        }
        // 以上的 while 迴圈做完後，會留下 pk <= n 的那些質數 p。
        // 也就是說，當前 primes 的大小就會是答案，將其輸出即可。
        cout << primes.size() << endl;
    }
}
