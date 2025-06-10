#include<stdio.h>
int count=0,d,x[10],w[10];

void subset(int cs,int k,int r){
    int i;
    x[k]=1;
    if(cs+w[k]==d){
        printf(" subset %d\n\n",++count);
        for(i=0;i<k;i++)
            if(x[i]==1)
                printf("%d\t",w[i]);

    }
    else if(cs +w[k]+w[k+1]){
        subset(cs+ w[k],k+1,r-w[k]);
    }
    if(cs +r-w[k]>=d && cs+w[k]<=d){
        x[k]=0;
        subset(cs,k+1,r-w[k]);
    }

}

int main(){
    int sum=0;
    int n;
    printf(" enter no of elem:\n");
    scanf("%d",&n);
    printf(" enter the sum");
    scanf("%d",&d);
    printf(" AO \n");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        sum+=w[i];
    }
    if(sum<d){
        printf(" no");
    }
    subset(0,0,sum);
    if(count==0){
        printf(" no");
    }
    return 0;
}