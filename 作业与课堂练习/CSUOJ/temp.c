#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct football{
	char name[50];
	int score;
	int ballpoint;
}team[10];

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

unsigned short cast1(const void *a){
    return 65535-((struct football*)a)->score;
}

unsigned short cast2(const void *a){
    return 65535-((struct football*)a)->ballpoint;
}

unsigned short cast3(const void *a){
    return ((struct football*)a)->name[0];
}

unsigned short cast4(const void *a){
    char x=((struct football*)a)->name[1];
    if (x=='\0') return 0;
    return x;
}

void rsort_4priorities_16bits(void *start,unsigned long total_elem,unsigned long size,unsigned short(*cast1)(const void *),unsigned short(*cast2)(const void *),unsigned short(*cast3)(const void *),unsigned short(*cast4)(const void *)){
    void *b = (void*)malloc(size*total_elem);unsigned long sum[4][65536]={0};
    int i;void *ptr=start,*end=start+(total_elem-1)*size,
               *startb=b,*endb=startb+(total_elem-1)*size;

    for (;ptr<=end;ptr+=size){
        sum[0][cast4(ptr)]++;
        sum[1][cast3(ptr)]++;
        sum[2][cast2(ptr)]++;
        sum[3][cast1(ptr)]++;
    }
    for (i=1;i<=65535;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[0][cast4(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[1][cast3(ptr)])*size,ptr,size);
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[2][cast2(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[3][cast1(ptr)])*size,ptr,size);
    free(b);
}


int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		getchar();
		for(int i=0;i<n*(n-1)/2;i++){
			char c=0;
			char name1[50]={0},name2[50]={0};
		    int score1=0,score2=0;
			for(int j=0;(c=getchar())!=':';j++){
				name1[j]=c;
			}
			scanf("%s",name2);
			scanf("%d:%d",&score1,&score2);
			getchar();
			int cnt=2,left=100,right=100;
			if(i==0){
					strcpy(team[0].name,name1);
					strcpy(team[1].name,name2);
					if(score1>score2){
				team[0].score +=3;
				team[0].ballpoint +=(score1-score2);
			}
			else if(score1==score2){
				team[0].score +=1;
				team[1].score +=1;
			}
			else {
				team[1].score +=3;
				team[1].ballpoint +=(score2-score1);
			}
				}
			else{
				int sum=cnt;
				for(int j=0;j<sum;j++){
				if(strcmp(name1,team[j].name)==0){
					left=j;
				}
				if(strcmp(name2,team[j].name)==0){
					right=j;
				}
			}
			if(left!=100&&right!=100){
			if(score1>score2){
				team[left].score +=3;
				team[left].ballpoint +=(score1-score2);
			}
			else if(score1==score2){
				team[left].score +=1;
				team[right].score +=1;
			}
			else {
				team[right].score +=3;
				team[right].ballpoint +=(score2-score1);
			}	
			}
			else if(left!=100&&right==100){
				strcpy(team[cnt].name,name2);
				if(score1>score2){
				team[left].score +=3;
				team[left].ballpoint +=(score1-score2);
			}
			else if(score1==score2){
				team[left].score +=1;
				team[cnt].score +=1;
			}
			else {
				team[cnt].score +=3;
				team[cnt].ballpoint +=(score2-score1);
			}	
				cnt++; 
			}
			else if(left==100&&right!=100){
				strcpy(team[cnt].name,name1);
				if(score1>score2){
				team[cnt].score +=3;
				team[cnt].ballpoint +=(score1-score2);
			}
			else if(score1==score2){
				team[cnt].score +=1;
				team[right].score +=1;
			}
			else {
				team[right].score +=3;
				team[right].ballpoint +=(score2-score1);
			}	
				cnt++; 
			} 
			else if(left==100&&right==100){
				strcpy(team[cnt].name,name1);
				cnt++;
				strcpy(team[cnt].name,name2);
				if(score1>score2){
				team[cnt-1].score +=3;
				team[cnt-1].ballpoint +=(score1-score2);
			}
			else if(score1==score2){
				team[cnt-1].score +=1;
				team[cnt].score +=1;
			}
			else {
				team[cnt].score +=3;
				team[cnt].ballpoint +=(score2-score1);
			}
			cnt++;
			}
		}
	}
	rsort_4priorities_16bits(team,n,sizeof(struct football),cast1,cast2,cast3,cast4);
	for(int i=0;i<n;i++){
		printf("%s ",team[i].name);
	}
	printf("\n");
}
	return 0;
}