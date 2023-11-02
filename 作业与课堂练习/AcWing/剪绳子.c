int maxProductAfterCutting(int length){
	int max=1,xi,i,j;
	if (length==2) return 1;
	else if (length==3) return 2;
    for (i=1;i<length;i++){
    	int p=1;xi=length/i;
    	for (j=0;j<length%i;j++){
    		p*=xi+1;
		}
		for (j=length%i;j<i;j++){
			p*=xi;
		}
		max=max>p?max:p;
	}
	return max;
}
