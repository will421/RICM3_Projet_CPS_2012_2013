/* Projet C.cpp : définit le point d'entrée pour l'application console.


*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "util.h"
#include "ppm.h"
#include "pgm.h"

int getBluePart(uint64_t data) {
    return data & 0xFFFF;
}

int getGreenPart(uint64_t data) {
    return (data >> 16) & 0xffff;
}

int getRedPart(uint64_t data) {
    return data >> 32 & 0xffff;
}

void printData(image *img) {
    unsigned int i;
    if (img != NULL && img->data != NULL) {
        printf("\tData :");
        if (img->t == P1) {
            for (i = 0; i < img->l * img->h; i++) {
                if (i % img->l == 0) printf("\n\t\t");
                printf("%d ", (int) img->data[i]);
            }
        } else {
            for (i = 0; i < img->l * img->h; i++) {
                if (i % img->l == 0) printf("\n\t\t");
                printf("%d ", getRedPart(img->data[i]));
                printf("%d ", getGreenPart(img->data[i]));
                printf("%d ", getBluePart(img->data[i]));
            }
        }
    }
}

int main(int argc, char* argv[])
{
	/*int option; // 0 => g / 1 => d
	char * nomFichier;
	FILE *f;
	if(*(argv+1)=="-g") { 
		option = 0;
	}
	else if (*(argv+1)=="-d") {
		option = 1;
	}
	else { printf("Erreur : Option %s inconnu\n",argv[1]); return 1;}

	if(*(argv+2)) {
		f = fopen(*(argv+2),"r");
	}
	else {
		f = NULL;
	}
	if (f==NULL)
	{
		f = stdin;
	}*/
	
	FILE *fileSource = NULL;
   FILE *fileDest = NULL;
   char *sourceName = NULL;
   char *destName = NULL; 
   image *img = NULL;
   int i;
   
   float a = 0.299,b=0.587,c=0.114;
   
   sourceName = *(argv+1);
	
	fileSource = fopen(sourceName,"r");

	img = readppm(fileSource);

	coloredtogray(img,a,b,c);
	
	
	
	fileDest = fopen("out.pgm", "w+");
	if(fileDest == NULL) printf("BOOOO\n");
	
	i = writepgm(fileDest,img);
	printf("%d",i);
	
	printf("img -> type : %d\n",img->t);
	printf("img -> l : %d\n",img->l);
	printf("img -> h : %d\n",img->h);
	printf("img -> max : %d\n",img->vmax);
	
}

