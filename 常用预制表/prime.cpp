#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(){
	int i,j;double sqt;char *a;
	ofstream outfile;
    outfile.open("x.c");
    outfile<<"#include <stdio.h> \n int prime[]={";
	for (i=1;i<5000001;i++){
		sqt=sqrt((double)i);
		for (j=2;(double)j<=sqt;j++){
			if (!(i%j)) goto next;
		}
        outfile<<i<<", ";
		next:;
	}
    outfile<<"};int main(){int T,L,R,i,j,k,t;scanf(\"%d\",&T);for (t=0;t<T;t++) {scanf(\"%d%d\",&L,&R);for (k=i=0;prime[i]<L;i++);for (j=i+1;prime[j]<=R;j++) k+=(prime[j]-prime[j-1]==2);printf(\"%d\\n\",k);}}";
    outfile.close();
	return 0;
}