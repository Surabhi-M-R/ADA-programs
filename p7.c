#include<stdio.h>
int n,p[10],w[10];
int max(int a,int b){
    return a>b?a:b;
}
int knap(int i,int m){
    if(i==n) return w[i]>m?0:p[i];
    if(w[i]>m) return knap(i+1,m);
    return max(knap(i+1,m),knap(i+1,m-w[i])+p[i]);
}
int main(){
    int m;
    printf("capacity");
    scanf("%d",&m);
    printf("ele");
    scanf("%d",&n);
    printf(" weight then profit");
    for(int i=0;i<n;i++){
        scanf("%d %d",&w[i],&p[i]);
    }
    int max_profit=knap(1,m);
    printf("%d",max_profit);

    return 0;
}