#include <bits/stdc++.h>
using namespace std;

int func(){
    int x,y,z;
    char a[7];
    scanf("%s",a);
    if(a[0] == 'f'){
        x = func();
        return 2*x - 3;
    }else if(a[0] == 'g'){
        x = func();
        y = func();
        return 2*x + y - 7;
    }else if(a[0] == 'h'){
        x = func();
        y = func();
        z = func();
        return 3*x - 2*y + z; 
    }else {
        return atoi(a);
    }
    
}


int main(){
    printf("%d",func());
    return 0;
}