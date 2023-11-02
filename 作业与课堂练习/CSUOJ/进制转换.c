#include<stdio.h>

int div(int x,int y){
	if ((x%y)<0) return (x/y)+1;
	else return (x/y);
}

int mod(int x,int y){
	if ((x%y)<0) return (x%y)-y;
	else return (x%y);
}

int main(){
	int n,r,i,j;char revs[200],res[200];
	while (scanf("%d %d",&n,&r)!=EOF){
		i=0;int a,b;
		printf("%d=",n);
		while (n){
			a=div(n,r);b=mod(n,r);
			if (b>9) revs[i]=b+55;
			else revs[i]=b+48;
			n=a;i++;
		}
		i--;
		for (j=0;j<=i;j++){
			res[j]=revs[i-j];
		}
		res[j]='\0';
		printf("%s(base%d)\n",res,r);
	}
	return 0;
}
