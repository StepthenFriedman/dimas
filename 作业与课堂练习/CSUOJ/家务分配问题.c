#include <stdio.h>
int main(){
    int k,i,j,a1,a2,a3,b1,b2,b3,ast,bst;
    while (~scanf("%d",&k)){
        for (i=0;i<k;i++){
            scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3);
            if (a1==1) a1=9;
            if (a2==1) a2=9;
            if (a3==1) a3=9;
            if (b1==1) b1=9;
            if (b2==1) b2=9;
            if (b3==1) b3=9;
            if (a1==a2&&a1==a3) ast=3000+100*a1;
            else if (a1==a2) ast=2000+100*a1+a3;
            else if (a1==a3) ast=2000+100*a1+a2;
            else if (a2==a3) ast=2000+100*a2+a1;
            else {
                if (a1==9) a1=1;
                if (a2==9) a2=1;
                if (a3==9) a3=1;
                ast=a1+a2+a3;
            }
            if (b1==b2&&b1==b3) bst=3000+100*b1;
            else if (b1==b2) bst=2000+100*b1+b3;
            else if (b1==b3) bst=2000+100*b1+b2;
            else if (b2==b3) bst=2000+100*b2+b1;
            else {
                if (b1==9) b1=1;
                if (b2==9) b2=1;
                if (b3==9) b3=1;
                bst=b1+b2+b3;
            }
            if (ast>bst) printf("lcy\n");
            else if (ast<bst) printf("Ypop\n");
            else printf("Draw\n");
        }
    }
}