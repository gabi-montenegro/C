#define n 5
int medias(int *vec){
	int soma=0;
	
	for (int i=0;i<n;i++){
		soma+=*(vec+i);
    }

	int media = (soma/n);
	return media;
	
}

