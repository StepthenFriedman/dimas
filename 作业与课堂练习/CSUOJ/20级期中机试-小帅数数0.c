#include <stdio.h>

int main(){
    int n,fivs,twos,i,x;
    while (~scanf("%d",&n)){
        fivs=twos=0;
        for (i=2;i<=n;i++){
            x=i;
            while (!(x%2)){
                x/=2;twos++;
            }
            while (!(x%5)){
                x/=5;fivs++;
            }
        }
        fivs=fivs<twos?fivs:twos;
        printf("%d\n",fivs);
    }
    
}