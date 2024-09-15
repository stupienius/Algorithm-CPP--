#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string input;
  re: while(cin >> input){
    stack<char> s;
    for(auto a : input){
      if(a == '(' || a == '[' || a=='{'){
        s.push(a);
      }else{
        if(s.top() == a-1 || s.top() == a-2){
          s.pop();
        }else{
          cout << "no\n";
          goto re;
        }
      }
    }
    if(!s.empty()) cout << "no\n";
    else  cout << "yes\n";
  }

  return 0;
}
