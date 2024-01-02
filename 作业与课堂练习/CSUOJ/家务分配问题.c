#include <stdio.h>
int main(){
    int k,i,j,a[3],b[3],ast,bst;
    while (~scanf("%d",&k)){
        while (k--){
            scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
            if (a[0]==a[1]&&a[0]==a[2]) {
                for (i=0;i<3;i++) if (a[i]==1) a[i]=9;
                ast=3000+100*a[0];
                goto aend;
            }
            for (i=0;i<3;i++) if (a[i]==a[(i+1)%3]) {
                for (j=0;j<3;j++) if (a[j]==1) a[j]=9;
                ast=2000+100*a[i]+a[(i+2)%3];
                goto aend;
            }
            ast=a[0]+a[1]+a[2];
            aend:;
            if (b[0]==b[1]&&b[0]==b[2]) {
                for (i=0;i<3;i++) if (b[i]==1) b[i]=9;
                bst=3000+100*b[0];
                goto bend;
            }
            for (i=0;i<3;i++) if (b[i]==b[(i+1)%3]) {
                for (j=0;j<3;j++) if (b[j]==1) b[j]=9;
                bst=2000+100*b[i]+b[(i+2)%3];
                goto bend;
            }
            bst=b[0]+b[1]+b[2];
            bend:;
            if (ast>bst) printf("lcy\n");
            else if (ast<bst) printf("Ypop\n");
            else printf("Draw\n");
        }
    }
}