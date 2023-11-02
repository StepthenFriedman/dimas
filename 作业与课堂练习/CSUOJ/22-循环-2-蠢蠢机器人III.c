#include<stdio.h>

int main(){
	char cmd[5];int m,dir;double x,y,go;
	while (scanf("%d",&m)!=EOF){
		dir=0;x=y=0.;
		for (int i=0;i<m;i++) {
			scanf("%s",&cmd);
			if (cmd[0]=='G'){
				scanf("%lf",&go);
				switch (dir%4){
					case 0:y+=go;continue;
					case 1:x+=go;continue;
					case 2:y-=go;continue;
					case 3:x-=go;continue;
				}
			}else{
				dir++;
			}
		}
		printf("%.3f %.3f\n",x,y);
	}
	
	return 0;
}
