#include <stdio.h>
#include <string.h>
#define INT_MAX 999999
int mc[50][50];
int min(int a, int b){
   if(a < b)
      return a;
   else
      return b;}
int DynamicProgramming(int c[], int i, int j){
   if (i == j) {
      return 0;}
   if (mc[i][j] != -1) {
      return
         mc[i][j];}
   mc[i][j] = INT_MAX;
   for (int k = i; k < j; k++) {
      mc[i][j] = min(mc[i][j], DynamicProgramming(c, i, k) + DynamicProgramming(c, k + 1, j) + c[i - 1] * c[k] * c[j]);
   }
   return mc[i][j];
}
int Matrix(int c[], int n){
   int i = 1, j = n - 1;
   return DynamicProgramming(c, i, j);
}
int main(){
   int arr[] = {3,4,5,2 };
   int n = sizeof(arr) / sizeof(arr[0]);
   memset(mc, -1, sizeof mc);
   printf("Minimum number of multiplications is: %d", Matrix(arr, n));
}

