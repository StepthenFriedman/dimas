#include <stdio.h>

int main(){
	int AH,AM,AS,BH,BM,BS,rh=0,rm=0,rs=0;
	while (scanf("%d %d %d %d %d %d",&AH,&AM,&AS,&BH,&BM,&BS)!=EOF){
		rh=0;rm=0;rs=0;
		rs+=AS+BS;
		if (rs>=60) {
			rs-=60;rm++;
		}
		rm+=AM+BM;
		if (rm>=60) {
			rm-=60;rh++;
		}
		rh+=AH+BH;
		printf("%d %d %d\n",rh,rm,rs);
	}
	return 0;
}
