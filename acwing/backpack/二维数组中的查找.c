bool searchArray(int** array, int arrayRowSize, int arrayColSize, int target) {
    int i=0,j=0;
    for (j=0;j<arrayRowSize&array[j][0]<=target;j++){
    	if (array[j][arrayColSize-1]>=target) for (i=0;i<arrayColSize&array[j][i]<=target;i++) {
    		if (array[j][i]==target) return true;
		}
	}
    return false;
}
