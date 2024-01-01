#include<stdio.h>
#include<string.h>

int max(int x,int y){return x>y?x:y;}

int min(int x,int y){return x<y?x:y;}

int main(){
    int t,n,res;int a[27][2005];
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        res=0;
        scanf("%d",&n);
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            for(int j=1;j<=26;j++)
                a[j][i]=a[j][i-1]+(x==j);
        }
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                int x=0,y=0;
                for(int k=1;k<=26;k++){
                     x=max(x,a[k][r]-a[k][l-1]);
                     y=max(y,min(a[k][l-1],a[k][n]-a[k][r])*2);
                }
                res=max(res,x+y);
            }
        }
        printf("%d\n",res);
    }
}