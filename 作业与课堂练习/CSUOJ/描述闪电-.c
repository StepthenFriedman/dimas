#include <stdio.h>
int main()
{int m,n,i;
while(scanf("%d",&m)!=EOF){
	for(i=1;i<=(m*2+1);i++){if(i<=m){
	
		for(n=m-i+1;n>0;n--)
		putchar(' ');putchar('*');printf("\n"); 
}if(i==m+1){for(n=m+1;n>0;n--) putchar('*');printf("\n");

}
if(i>m+1){for(n=m*2-i+1;n>0;n--)putchar(' ');putchar('*');printf("\n");
}
	
		
		

		
	}
printf("\n");}return 0;
}
