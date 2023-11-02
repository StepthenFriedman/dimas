int maxProductAfterCutting(int length){
	if (length==2) return 1;
	if (length==3) return 2;
    int res=1,a=length/3,b=length%3;
    if (b==1){
        res=4; for (int i=1;i<a;i++) res*=3;
    }
    else if (b==2){
        res=2; for (int i=0;i<a;i++) res*=3;
    }
    else for (int i=0;i<a;i++) res*=3;
	return res;
}
