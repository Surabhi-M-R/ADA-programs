#include<stdio.h>
int knapsack(int n,int W, int values[],int weights[]){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0|| w==0) dp[i][w]=0;
            else if(weights[i-1]<=w){
                dp[i][w]=(values[i-1]+dp[i-1][w-weights[i-1]])>dp[i-1][w]?
                (values[i-1]+dp[i-1][w-weights[i-1]]):dp[i-1][w];
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];

}
int main(){
    int n,W;
    printf("items\n");
    scanf("%d",&n);
    printf("capacity");
    scanf("%d",&W);
    int weights[n],values[n];
    printf(" enter");
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&values[i]);
    }
    int max_profit=knapsack(n,W,weights,values);
    printf("%d",max_profit);
    return 0;
}