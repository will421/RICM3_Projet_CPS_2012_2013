#include "pgm.h"

int writepgm(FILE * destFile, image* img){
	int i;
	uint64_t size;
	
	if( destFile == NULL || img == NULL || img->data == NULL || img->t != P2){
		return EXIT_FAILURE;
	}
	
	size = img->l * img->h;
	
   fprintf(destFile, "%s\n",typeToString(img->t));
   fprintf(destFile, "%u %u\n", img->l, img->h);
   printf("%d\n",img->vmax);
   fprintf(destFile, "%d\n", img->vmax);
   
   for(i = 0;i<size;i++){
   	if( i%img->l == 0) {fprintf(destFile, "\n");}
   	fprintf(destFile, "%d ", img->data[i] );
   }
	
	return EXIT_SUCCESS;
}
