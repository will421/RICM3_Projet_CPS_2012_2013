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
    
        img = readppmIn();
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
