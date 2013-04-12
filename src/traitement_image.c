/* Projet C.cpp : définit le point d'entrée pour l'application console.


*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "util.h"
#include "ppm.h"
#include "pgm.h"
#include "pbm.h"

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

void usage() {
    printf("Usage : traitement_image [-g|-d] (FILE.ppm)\n");
}

void message(char * mess) {
    printf("Message : %s\n",mess);
 }
    
void verifppm(char * filename) {
     printf("%s\n",filename);
    char * extension = strrchr(filename,'.');
    if (extension==NULL || strcmp(extension,".ppm")!=0) {
        message("Format de fichier inconnu. \".ppm\" demandé");
        usage();
        exit(0);
    }
}

char * modifExtention(char * sourceName,int option) {
    int size = strlen(sourceName);
    char * res = (char *)malloc(sizeof(char)*size);
    strcpy(res,sourceName);
    *(res+size-2) = option ? 'b' : 'g';
    trace(sourceName);
    trace(res);
    return res;
}



int main(int argc, char* argv[])
{
    int option; /* 0 => g / 1 => d */
    int bfile; /* Si un fichier est donnée en parametre ou non 0->non / 1->oui */
    FILE *fileSource = NULL;
    FILE *fileDest = NULL;
    char *sourceName = NULL;
    char *destName = NULL; 
    image *img = NULL;
    int i;
    
    float a = 0.299,b=0.587,c=0.114,alpha=0.5;
    
    if(argc==1) {
        usage();
        return 0;
    } else if (argc>1) {
        if (strcmp(argv[1],"-g")==0) {
            option = 0;
        }
        else if (strcmp(argv[1],"-b")==0) {
            option = 1;
        } else {
            message("Option inconnu");
            usage();
            return 0;
        }
        if (argc>2) {
            bfile = 1;
            sourceName= *(argv+2);
            verifppm(sourceName);
            if (argc>3) {message("Parametres supplémentaires ignorés");}
        } else {
            bfile = 0;
            
        }  
    }

    if(bfile) {
        fileSource = fopen(sourceName,"r"); 
        if (fileSource==NULL) { 
            message("Erreur à l'ouverture du fichier"); 
            return 0;
        }
        img = readppm(fileSource); 
    } else {
    
        /* img = tafonction kikou */
    }
     
    if (option) {
        coloredtoBW(img,alpha);
    } else {
        coloredtogray(img,a,b,c); 
    }
	
	if(bfile) {
	    destName = modifExtention(sourceName,option);
	} else
	{
	    destName = option ? "image.pbm" : "image.pgm";
	}
	
	fileDest = fopen(destName, "w+");
	if(fileDest == NULL) {message("erreur à l'ouverture du fichier de sortie"); return 0;};
	if (option) {
	    i = writepbm(fileDest,img);
	} else {
	    i = writepgm(fileDest,img);
	}
	if (i== EXIT_FAILURE) {
	    message("Erreur lors de l'écriture");
	}
	
	printf("img -> type : %d\n",img->t);
	printf("img -> l : %d\n",img->l);
	printf("img -> h : %d\n",img->h);
	printf("img -> max : %d\n",img->vmax);
    
    return 0;
}
