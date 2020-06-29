#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int cnt = 1;
  int tmp = 0;
  for(int j=0;j<n;j++){
    if(A[j]>x){
      return 0;
    }
    if(tmp+A[j]<=x){
      tmp += A[j];
    }
    else{
      cnt++;
      tmp = A[j];
    }
  }
  return cnt <= k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub-lb>1){
    int mid = (lb+ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}
