#include <stdio.h>

//��Ŀ����˼��:ÿ�����ľ��붼���ٵ�һ��U��F%,ֱ������0 

int main(){
	float H,U,D,F,m;int day;
	while (1) {
		scanf("%f %f %f %f",&H,&U,&D,&F);
		if (H+U+D+F<0.01) break;
		float k=(F/100.)*U;
		m=0;day=1;
		again:
		m+=U;
		if (m>H){printf("success on day %d\n",day);continue;}
		m-=D;
		if (m<0.){printf("failure on day %d\n",day);continue;}
		U-=k;
		if (U<0.) U=0.;
		day++;
		goto again;
	}
	return 0;
}
