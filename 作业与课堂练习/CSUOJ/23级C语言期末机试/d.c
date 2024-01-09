#include <stdio.h>

int main(){
    int n,m,i,j,k,del,skip;
    while (~scanf("%d%d",&n,&m)){
        int map[n][m],res[n][m];
        for (i=0;i<n;i++) for (j=0;j<m;j++) scanf("%d",&map[i][j]),res[i][j]=map[i][j];
        for (i=0;i<n;i++) for (j=0;j<m-2;j++) {
            for (k=1;j+k<m && map[i][j+k]==map[i][j];k++);
            if (k>=3) for (del=0;del<k;del++) res[i][j+del]=0;
        }
        for (j=0;j<m;j++) for (i=0;i<n-2;i++) {
            for (k=1;i+k<n && map[i+k][j]==map[i][j];k++);
            if (k>=3) for (del=0;del<k;del++) res[i+del][j]=0;
        }
        for (i=0;i<n;i++) {for (j=0;j<m;j++) printf("%d ",res[i][j]);putchar('\n');}
        putchar('\n');
    }
    return 0;
}