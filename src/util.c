#include "util.h"

void trace(char * message) {
        printf("trace :%s\n",message);
}

/* Lit le type d'une image */
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

/* Lit les dimmensions d'une image */
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

/* Lit la valeur max */
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
/* Converti un PPM en PBM */
void coloredtoBW( image * im,float alpha) {
   uint64_t nbpixel = (im->l * im->h);
   uint64_t * data = im->data ;
	uint64_t i;
	for(i=0;i<=nbpixel;i++) {
	        RGBtoBW(data+i,im->vmax,alpha);
	}
	im->t = P1;
}

/* Prend RGB et convertis en noir et blanc en fonction de l'alpha */
void RGBtoBW(uint64_t *pixel,int vmax,float alpha) {
        uint16_t r,g,bl;
        getColor(pixel,&r,&g,&bl);
        int val = (r*g*bl)/vmax;
        *pixel = val<alpha ? 0 : 1 ;
}

/* Converti un PPM en PGM  */
void coloredtogray( image * im,float a,float b,float c)
{
	uint64_t nbpixel = (im->l * im->h);
	uint64_t * data = im->data ;
	uint64_t i;
	for(i=0;i<=nbpixel;i++) {
	        RGBtoGrey(data+i,a,b,c);
	}
	im->t = P2;
}


/* Prend RGB et convertis en gris avec les constantes associés */
void RGBtoGrey(uint64_t *pixel,float a,float b,float c) {
        uint16_t r,g,bl;
        getColor(pixel,&r,&g,&bl);
        *pixel = a*r + b*g + c*bl;
}

/* Prend un entier sur 64 bit et retourne le (r,g,b) */
void getColor(uint64_t const *pixel, uint16_t *r,uint16_t *g,uint16_t *b) {
	int decalr = 32;
	int decalg = 16;
	int decalb = 0;
	int mask = 65535;
	
	*r = (*pixel >> decalr /*decalage*/ ) & mask;
	*g = (*pixel >> decalg /*decalage*/ ) & mask;
	*b = (*pixel >> decalb /*decalage*/ ) & mask;

}

char * typeToString(typeImage type){

	if(type == 1){
	        return "P1";
	} else if (type == 2 ) {
	        return "P2";
	}
	else if ( type == 3 ) {
	        return "P3";
	} else {
	        return  "";
	 }
}
