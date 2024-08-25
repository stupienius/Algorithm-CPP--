#include <stdio.h>

int main(){
  
  int n;
  scanf("%d",&n);

  int count[102] = {0};

  int input;

  while(n--){
    scanf("%d",&input);
    count[input] ++;
  }
  
  for(int i=1;i<101;i++){
    for(int j=0;j<count[i];j++){
      printf("%d ",i);
    }
  }
  return 0;
}
