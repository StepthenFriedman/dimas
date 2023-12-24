#include<stdio.h>

int main(){
    int N,M,i,j,k,pl,sum;
    while (~scanf("%d%d",&N,&M)){
        long long mat[2][N][N],init[N][N];
        for (i=0;i<N;i++) for (j=0;j<N;j++) scanf("%lld",&init[i][j]);
        for (i=0;i<N;i++) for (j=0;j<N;j++) mat[1][i][j]=(i==j);
        for (k=0;k<M;k++){
            for (i=0;i<N;i++){
                for (j=0;j<N;j++){
                    sum=0;
                    for (pl=0;pl<N;pl++){
                        sum+=mat[!(k%2)][pl][j]*init[i][pl];
                    }
                    mat[k%2][i][j]=sum;
                }
            }
        }
        for (i=0;i<N;i++){
            for (j=0;j<N;j++){
                printf("%lld ",mat[!(M%2)][i][j]);
            }
            putchar('\n');
        }
        end:;
    }
    return 0;
}