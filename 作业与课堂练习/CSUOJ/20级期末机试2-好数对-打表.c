#include<stdio.h>
int fine[2001]={0};
int main(){
    int i,j,k,res=0;
    for (i=2;i<=2000;i++){
        res=0;
        for (j=2;j<i;j++) {
            for (k=j+1;k<i;k++){
                if (!((j*k)%(j+k))){
                    res++;
                }
            }
        }
        fine[i]=res;
    }
    for (i=1;i<=2000;i++) printf("%d,",fine[i]);
    return 0;
}