#include<stdio.h>
#include <stdlib.h>

int main(){
	int n,sum=0,add,times,max,min,ipt,*pj;
	register int i;
	scanf("%d",&n);
	int* sort=calloc(1000000,sizeof(int));
	scanf("%d",&ipt);max=min=ipt;sort[ipt]++;
	for(i=1;i<n;i++){
		scanf("%d",&ipt);
		max=max>ipt?max:ipt;
		min=min<ipt?min:ipt;
		sort[ipt]++;
	}
	i=min;pj=&sort[max+1];
	for (times=0;times<n-1;times++){
		while (!sort[i]) i++;
		if (i<=max) sort[add=i]--;
		else {
			add=sort[i];sort[i]=0;
		}
		while (!sort[i]) i++;
		if (i<=max){
			sort[i]--;add+=i;
		}
		else {
			add+=sort[i];sort[i]=0;
		}
		sum+=add;
		if (add>max) *(pj++)=add;
		else sort[add]++;
	}
	free(sort);
	printf("%d\n",sum);
	return 0;
}
