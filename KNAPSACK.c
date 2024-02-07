#include <stdio.h> 
int max(int a, int b) { return (a > b) ? a : b; } 
int knapSack(int W, int wt[], int val[], int n) 
{  
    if (n == 0 || W == 0) 
        return 0; 

    else if (wt[n - 1] > W) 
        return knapSack(W, wt, val, n - 1); 

    else
        return max( 
            val[n - 1] 
                + knapSack(W - wt[n - 1], wt, val, n - 1), 
            knapSack(W, wt, val, n - 1)); 
} 
int main() 
{ 
    int profit[] = { 5,10,11}; 
    int weight[] = { 60,70,80 }; 
    int W = 160; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    printf("%d is the total profit earned.", knapSack(W, weight, profit, n)); 
    return 0; 
}

