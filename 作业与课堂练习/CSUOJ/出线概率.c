#include <stdio.h>

int main(){
	char ipt[100000];int i;
	while (scanf("%s",&ipt)!=EOF){
        for (i=0;(ipt[i]!='\0');i++);
        if (i%2){
            printf("-0.");
            for (i--;i>0;i-=2) printf("%02d",(ipt[i]-96)*10-(ipt[i-1]-96));
            printf("%d",ipt[0]-96);
        }
        else{
            printf("0.");
            for (i--;i>0;i-=2) printf("%02d",(ipt[i]-96)*10-(ipt[i-1]-96));
        }
        putchar('\n');
	}
	return 0;
}
