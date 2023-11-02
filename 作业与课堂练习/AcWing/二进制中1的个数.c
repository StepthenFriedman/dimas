int NumberOf1(int n){
	int res=0;
	if (n>=0) do{
		res+=n%2;n>>=1;
		printf("%d\n",n);
	}while (n);
	else {
		n=~n;
		do{
			res+=n%2;n>>=1;
		}while (n);
		res=32-res;
	}
    return res;
}
