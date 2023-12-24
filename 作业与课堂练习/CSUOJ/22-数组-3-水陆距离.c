#include <stdio.h>
#include <string.h>
//BFS
unsigned int arr[1000][1000], wateri[1000000], waterj[1000000], res[1000][1000];

int main(){
    int n,m,i,j,k,wl,t;
    while (~scanf("%d%d",&n,&m)){
        if (!(n+m)) break;
        memset(res,0b[0]1111111,1000*1000*4);
        for (i=0;i<n;i++) {
            for (j=0;j<m;j++) printf("%u ",res[i][j]);
            putchar('\n');
        }
        for (k=i=0;i<n;i++) for (j=0;j<m;j++) {
            scanf("%1u",&arr[i][j]);
            if (!arr[i][j]) {
                wateri[k]=i;
                waterj[k++]=j;
                res[i][j]=0;
            }
        }
        wl=k;t=1;
        for (k=0;k<wl;k++) {
            if (wateri[k]>0 && res[wateri[k]-1][waterj[k]]>res[wateri[k]][waterj[k]]+1) {
                res[wateri[k]-1][waterj[k]]=res[wateri[k]][waterj[k]]+1;
                wateri[wl]=wateri[k]-1;
                waterj[wl++]=waterj[k];
            }
            if (waterj[k]>0 && res[wateri[k]][waterj[k]-1]>res[wateri[k]][waterj[k]]+1) {
                res[wateri[k]][waterj[k]-1]=res[wateri[k]][waterj[k]]+1;
                wateri[wl]=wateri[k];
                waterj[wl++]=waterj[k]-1;
            }
            if (wateri[k]<n-1 && res[wateri[k]+1][waterj[k]]>res[wateri[k]][waterj[k]]+1) {
                res[wateri[k]+1][waterj[k]]=res[wateri[k]][waterj[k]]+1;
                wateri[wl]=wateri[k]+1;
                waterj[wl++]=waterj[k];
            }
            if (waterj[k]<m-1 && res[wateri[k]][waterj[k]+1]>res[wateri[k]][waterj[k]]+1) {
                res[wateri[k]][waterj[k]+1]=res[wateri[k]][waterj[k]]+1;
                wateri[wl]=wateri[k];
                waterj[wl++]=waterj[k]+1;
            }
        }
        for (i=0;i<n;i++) {
            for (j=0;j<m;j++) printf("%u ",res[i][j]);
            putchar('\n');
        }
    }
}