#ifndef _H
#define _H

#define DEBUG 0

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef enum typeImage {
	P1=1, 			
	P2=2, 			
	P3=3  			
} typeImage;

typedef struct image {
	enum typeImage t;		
	uint32_t l;			
	uint32_t h;			
	int vmax;			
	uint64_t *data;	
} image;

/* Convertit un PPM en PGM */
void coloredtogray(image * i,float a,float b,float c);

/* Convertit un PPM en PBM */
void coloredtoBW(image * i,float alpha);

/* Lit le type d'une image */
int readType(FILE *sourceFile, typeImage *type);

/* Lit les dimmensions d'une image */
int readDimension(FILE *sourceFile, uint32_t *l, uint32_t *h);

/* Lit la valeur max */
int readMax(FILE *sourceFile,int *max);

/* Prend un entier sur 64 bit et retourne le (r,g,b) */
void getColor(uint64_t const *pixel, uint16_t *r,uint16_t *g,uint16_t *b);

#endif
