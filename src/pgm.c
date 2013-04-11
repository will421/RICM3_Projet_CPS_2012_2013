#include "pgm.h"

/* ecris l'image dans un fichier pgm */
int writepgm(FILE * destFile, image* img){
	int i;
	uint64_t size;
	
	if( destFile == NULL || img == NULL || img->data == NULL || img->t != P2){
		return EXIT_FAILURE;
	}
	
	size = img->l * img->h;
	
	/* fprintf(destFile, "%s\n",img->t); */
   fprintf(destFile, "%u %u\n", img->l, img->h);
   fprintf(destFile, "%llu\n", img->vmax);
   
   for(i = 0;i<size;i++){
   	if( i%img->l == 0) {fprintf(destFile, "\n");}
   	fprintf(destFile, "%d ", img->data[i] );
   }
	
	return EXIT_SUCCESS;
}
