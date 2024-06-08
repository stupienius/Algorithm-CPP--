#include <bits/stdc++.h>
using namespace std;

int func(){
    int x,y;
    char input[7];
    scanf("%s",input);
    if(input[0] == 'f'){
        x = func();
        return 2*x - 1; 
    }else if(input[0] == 'g'){
        x = func();
        y = func();
        return x + 2*y - 3;
    }else {
        return atoi(input);
    }
}

int main(){
    printf("%d",func());
    return 0;
}

