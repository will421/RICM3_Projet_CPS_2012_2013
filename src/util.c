#include "util.h"


// Lit le type d'une image
int readType(FILE *sourceFile, typeImage *type){
	char inType[3];
	int result = EXIT_SUCCESS,t;
	t = fscanf(sourceFile, "%2s", inType);
	printf("%s \n",inType);
	
	if(t == 1){
		if(strcmp(inType,"P1") == 0){
			*type = P1;
		}else if (strcmp(inType,"P2") == 0){
			*type = P2;
		}else if (strcmp(inType,"P3") == 0){
			*type = P3;
		}else{
			result = EXIT_FAILURE;
		}
	}else{
		result = EXIT_FAILURE;
	}
	return result;
}

// Lit les dimmensions d'une image
int readDimension(FILE *sourceFile, uint32_t *l, uint32_t *h){
	int la, ha,dim1, dim2;
   int result = EXIT_SUCCESS;
   dim1 = fscanf(sourceFile, "%*[ \t\n]%d", &la);
   dim2 = fscanf(sourceFile, "%*[ \t\n]%d", &ha);
   if (dim1 == 1 && dim2 == 1) {
       *l = la;*h = ha;
   } else{
   	result = EXIT_FAILURE;
   }
   return result;
}

// Lit la valeur max
int readMax(FILE *sourceFile,int *max){
	int maxVal = 0,result = EXIT_SUCCESS;
   int t;
   t = fscanf(sourceFile, "%*[ \t\n]%llu", &maxVal);
   if (t == 1 && maxVal < 65536) {
       *max = maxVal;
   } else{
   	result = EXIT_FAILURE;
   }
   return result;
}
