/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* replaceSpaces(char *str){
	int len=0,n=0;
    while (str[n]!='\0') {
    	if (str[n]==' ') len+=2;
    	len++;n++;
	}
	char *res;
	res=(char*)malloc(sizeof(char)*len);
	len=0;n=0;
	while (str[n]!='\0') {
		if (str[n]==' ') {
			res[len]='%';len++;
			res[len]='2';len++;
			res[len]='0';len++;
		}
		else {res[len]=str[n];len++;}
    	n++;
	}
	return res;
}
int main(){
	return 0;
}
