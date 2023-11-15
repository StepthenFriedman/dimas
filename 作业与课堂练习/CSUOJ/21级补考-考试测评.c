#include<stdio.h>

int main()
{
	int n,i,j;
	while(scanf("%d", &n)!=EOF){
		int math[n],eng[n],clang[n],score[n],indx[n],num[n],best=0,worst=300;
		for (j=0;j<n;j++) indx[j]=j;
		for (j=0;j<n;j++){
			scanf("%d%d%d%d",&num[j],&math[j],&eng[j],&clang[j]);
			score[j]=math[j]+eng[j]+clang[j];
			best=best>score[j]?best:score[j];
			worst=worst<score[j]?worst:score[j];
		}
		i=0;
		while (i<n-1){
			if (num[indx[i]]>num[indx[i+1]]){
				indx[i]=indx[i]^indx[i+1];
				indx[i+1]=indx[i]^indx[i+1];
				indx[i]=indx[i]^indx[i+1];
				if (i) i--;
			}
			else i++;
		}
		printf("BEST\n");
		for (j=0;j<n;j++) {
			if (score[indx[j]]==best) printf("%d %d %d %d %d\n",num[indx[j]],score[indx[j]],math[indx[j]],eng[indx[j]],clang[indx[j]]);
		}
		printf("WORST\n");
		for (j=0;j<n;j++) {
			if (score[indx[j]]==worst) printf("%d %d %d %d %d\n",num[indx[j]],score[indx[j]],math[indx[j]],eng[indx[j]],clang[indx[j]]);
		}
		putchar('\n');
	}
	return 0;
}
