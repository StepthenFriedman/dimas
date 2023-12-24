#include <stdio.h>
int cmp(const void *a,const void *b){
	return *(float*)a-*(float*)b;
}

int main()
{
	int n,i,j;
	while(scanf("%d", &n)!=EOF){
		float score[n][5];
		int indx[n];
		char num[n][4];
		for (j=0;j<n;j++) indx[j]=j;
		for (j=0;j<n;j++){
			scanf("%s",&num[j]);
			for (i=0;i<5;i++) scanf("%f",&score[j][i]);
			qsort(score[j],5,sizeof(float),cmp);
			score[j][0]=(score[j][1]+score[j][2]+score[j][3])/3.;
		}
		i=0;
		while (i<n-1){
			if (score[indx[i]][0]<score[indx[i+1]][0]){
				indx[i]=indx[i]^indx[i+1];
				indx[i+1]=indx[i]^indx[i+1];
				indx[i]=indx[i]^indx[i+1];
				if (i) i--;
			}
			else i++;
		}
		for (j=0;j<n;j++) {
			printf("%s %.2f\n",num[indx[j]],score[indx[j]][0]);
		}
	}
	return 0;
}
