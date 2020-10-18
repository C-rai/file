#include<stdio.h>

#define IMF 1000000007

int main(void){
  int n , m;
  scanf("%d %d",&n,&m);

 int a[m] , b[m] , c[m];
 for(int  i = 0;i < m;i ++){
   scanf("%d %d %d",&a[i],&b[i],&c[i]);
 }

 int flag = 1, h = m/1.3 , temp;
 while(flag){
   flag = 0;
   for(int i = 0;i < m;i ++){
     if(a[i] > a[i+h]){
       temp = a[i];
       a[i] = a[i+h];
       a[i+h] = temp;
       temp = b[i];
       b[i] = b[i+h];
       b[i+h] = temp;
       temp = c[i];
       c[i] = c[i+h];
       c[i+h] = temp;
       flag = 1;
     }
   }
 }

  int ans[10001] = {0};
  for(int i = 2;i <= 10000;i ++){
    ans[i] = IMF;
  }
  while(flag){
    flag = 0;
    for(int i = 0;i < m;i ++){
      if(ans[a[i]] == IMF){
        if(ans[b[i]] == IMF){
          flag = 1;
        }
        else{
          ans[a[i]] = ans[b[i]] + c[i];
          flag = 1;
        }
      }
      if(ans[b[i]] > ans[a[i]]+c[i]){
        ans[b[i]] = c[i];
      }
    }
  }

  long long kei = 0;
  for(int i = 0;i <= n;i ++){
    kei += (long long)ans[i];
  }

  printf("%lld\n",kei);

  return 0;


}