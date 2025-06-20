#include <bits/stdc++.h>
using namespace std;

void move(int ring,char from,char to,char tmp){
    if(ring > 1){
        move(ring-1,from,tmp,to);
        move(1,from,to,tmp);
        move(ring-1,tmp,to,from);
    }
    cout << "ring" << ring << "from" << from << "to" << to;
}

int main(){

    int n;
    cin >> n;

    move(n,'a','c','b');


    return 0;
}
