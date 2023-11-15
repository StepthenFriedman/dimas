#include <stdio.h>

int main(){
	char ipt[1000];
	int i,res;
	while (~scanf("%s",&ipt)){
		int n[3]={0};
		for (i=0;ipt[i]!='\0';i++) {
			switch (ipt[i]){
			case 'C':n[0]++;continue;
			case 'S':n[1]++;continue;
			case 'U':n[2]++;continue;
			}
		}
		res=n[0];
		res=res<n[1]?res:n[1];
		res=res<n[2]?res:n[2];
		printf("%d\n",res);
	}
}
