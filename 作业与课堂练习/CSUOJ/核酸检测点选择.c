#include <stdio.h>
#include <math.h>

int main(){
	int n,i,x,y,xi,yi,minx,miny,mini;
    float d,m;
	while (scanf("%d%d%d",&n,&x,&y)!=EOF){
        m=3.4028234664e+38;
        for (i=0;i<n;i++){
            scanf("%d%d",&xi,&yi);
            d=sqrt((float)((xi-x)*(xi-x)+(yi-y)*(yi-y)));
            if (m>d) mini=i+1,m=d,minx=xi,miny=yi;
        }
        printf("%d %d %d %.2f\n",mini,minx,miny,m);
	}
	return 0;
}
