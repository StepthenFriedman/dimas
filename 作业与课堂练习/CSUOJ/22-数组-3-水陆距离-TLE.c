#include <stdio.h>

void min(int*x, int y){
    *x=*x<y?*x:y;
}

int abs(int x){
    return x>0?x:-x;
}

int arr[1000][1000], wateri[1000], waterj[1000], res[1000][1000];

int main(){
    int n,m,i,j,k,wl;
    while (~scanf("%d%d",&n,&m)){
        for (k=i=0;i<n;i++) for (j=0;j<m;j++) {
            scanf("%1d",&arr[i][j]);
            if (!arr[i][j]) {
                wateri[k]=i;
                waterj[k++]=j;
            }
        }
        wl=k;
        for (i=0;i<n;i++) for (j=0;j<m;j++) {
            if (!arr[i][j]) res[i][j]=0;
            else {
                res[i][j]=100000;
                for (k=0;k<wl;k++) min(&res[i][j],abs(wateri[k]-i)+abs(waterj[k]-j));
            }
        }
        for (i=0;i<n;i++) {
            for (j=0;j<m;j++) printf("%d ",res[i][j]);
            putchar('\n');
        }

    }
}