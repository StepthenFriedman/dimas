#include <stdio.h>

int main(){
    int n,m,i,j,k,cmdx,cmdy,temp;char cmd;
	while (~scanf("%d%d",&n,&m)){
        int cube[n][n];
        for (i=0;i<n;i++) for (j=0;j<n;j++) cube[i][j]=i*n+j+1;
        for (i=0;i<m;i++){
            getchar();
            scanf("%c%d%d",&cmd,&cmdx,&cmdy);
            if (cmd=='L'){
                for (k=0;k<cmdy;k++){
                    temp=cube[cmdx-1][0];
                    for (j=0;j<n-1;j++){
                        cube[cmdx-1][j]=cube[cmdx-1][j+1];
                    }
                    cube[cmdx-1][n-1]=temp;
                }
            }
            else if (cmd=='R'){
                for (k=0;k<cmdy;k++){
                    temp=cube[cmdx-1][n-1];
                    for (j=n-1;j>0;j--){
                        cube[cmdx-1][j]=cube[cmdx-1][j-1];
                    }
                    cube[cmdx-1][0]=temp;
                }
            }
            else if (cmd=='D'){
                for (k=0;k<cmdy;k++){
                    temp=cube[n-1][cmdx-1];
                    for (j=n-1;j>0;j--){
                        cube[j][cmdx-1]=cube[j-1][cmdx-1];
                    }
                    cube[0][cmdx-1]=temp;
                }
            }
            else if (cmd=='U'){
                for (k=0;k<cmdy;k++){
                    temp=cube[0][cmdx-1];
                    for (j=0;j<n-1;j++){
                        cube[j][cmdx-1]=cube[j+1][cmdx-1];
                    }
                    cube[n-1][cmdx-1]=temp;
                }
            }

        }
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++){
                printf("%d ",cube[i][j]);
            }
        }
        putchar('\n');
    }
	return 0;
}