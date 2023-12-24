#include<stdio.h>

int main(){
    int N,M,i,j,k,pl,sum;
    while (~scanf("%d%d",&N,&M)){
        int mat[2][N][N];
        for (i=0;i<N;i++) for (j=0;j<N;j++) scanf("%d",&mat[1][i][j]);
        for (k=0;k<M;k++){
            for (i=0;i<N;i++){
                for (j=0;j<N;j++){
                    sum=0;
                    for (pl=0;pl<N;pl++){
                        sum+=mat[!(k%2)][pl][j]*mat[!(k%2)][i][pl];
                    }
                    mat[k%2][i][j]=sum;
                }
            }
        }
        for (i=0;i<N;i++){
            for (j=0;j<N;j++){
                printf("%d ",mat[(M%2)][i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}