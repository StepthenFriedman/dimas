#include<stdio.h>
#include<math.h>
int main()
{
	long long a[2],x,i,j,num,row,rem;
	while(scanf("%lld",&x)!=EOF){
		if (x==1) num=1;
		else if (x==2) num=2;
		else {
			a[0]=1;a[1]=2;
			for(i=2;a[!(i%2)]<x;i++) a[i%2]=a[i%2]+a[!(i%2)];
            num=i;
		}
        row=(long long)sqrt(num);
        while (row*row<num) row++;
        rem=row*row-num;rem=2*row-1-rem;
        printf("%*c\n",2*(int)(row)+1,'*');
        for (i=0;i<row-!!(rem);i++){
            printf("%*c",2*(int)(row-i)-1,' ');
            for (j=0;j<=i;j++) printf("/ \\ ");
            printf("\n");
            printf("%*c",2*(int)(row-i)-1,'*');
            for (j=0;j<=i;j++) printf("---*");
            printf("\n");
        }
        if (rem){
            printf(" / \\ ");
            j=1;
            while (j<rem){
                printf("/ ");j++;
                if (j>=rem) break;
                printf("\\ ");j++;
            }

            printf("\n*");
            for (j=0;j<(rem+1)/2;j++) printf("---*");
            printf("\n");
        }
	}
	return 0;
}