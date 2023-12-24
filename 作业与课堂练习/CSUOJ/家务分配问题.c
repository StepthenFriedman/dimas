#include <stdio.h>
int main(){
    int k,i,j,a[0],a[1],a[2],b[0],b[1],b[2],ast,bst;
    while (~scanf("%d",&k)){
        for (i=0;i<k;i++){
            scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
            for (i=0;i<3;i++) {
                if (a[i]==1) a[i]=9;
                if (b[i]==1) b[i]=9;
            }
            if (a[0]==a[1]&&a[0]==a[2]) ast=3000+100*a[0];
            else for (i=0;i<3;i++) if (a[i]==a[(i+1)%3]) ast=2000+100*a[i]+a[(i-1)%3];
            else {
                if (a[0]==9) a[0]=1;
                if (a[1]==9) a[1]=1;
                if (a[2]==9) a[2]=1;
                ast=a[0]+a[1]+a[2];
            }
            if (b[0]==b[1]&&b[0]==b[2]) bst=3000+100*b[0];
            else if (b[0]==b[1]) bst=2000+100*b[0]+b[2];
            else if (b[0]==b[2]) bst=2000+100*b[0]+b[1];
            else if (b[1]==b[2]) bst=2000+100*b[1]+b[0];
            else {
                if (b[0]==9) b[0]=1;
                if (b[1]==9) b[1]=1;
                if (b[2]==9) b[2]=1;
                bst=b[0]+b[1]+b[2];
            }
            if (ast>bst) printf("lcy\n");
            else if (ast<bst) printf("Ypop\n");
            else printf("Draw\n");
        }
    }
}