#include <stdio.h>
char ipt[10000000];
int main(){
	int i,n,sum;
	while (~scanf("%d",&n)){
		scanf("%s",ipt);
        int arr[4]={0};//k i n g
        sum=0;
		for (i=0;i<n;i++){
            switch (ipt[i]){
                case 'k':arr[0]++;continue;
                case 'i':arr[1]++;continue;
                case 'n':arr[2]++;continue;
                case 'g':arr[3]++;continue;
            }
        }
        while (arr[0]>=1&&arr[1]>=2&&arr[2]>=2&&arr[3]>=2){
            arr[0]-=1,arr[1]-=2,arr[2]-=2,arr[3]-=2,sum+=2;
        }
        while (arr[0]>=1&&arr[1]>=1&&arr[2]>=1&&arr[3]>=1){
            arr[0]-=1,arr[1]-=2,arr[2]-=2,arr[3]-=2,sum++;
        }
        printf("%d\n",sum);
	}
	return 0;
}