/**
 * \file util.h
 * \brief Operations générales liées aux images.
 * \author Corentin RICOU et William BOBO
 * \version 1
 * \date 11 avil 2013
 */

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

void trace(char * message);

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
void coloredtogray(image * i,float a,float b,float c);

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
void RGBtoGrey(uint64_t *pixel,float a,float b,float c);

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
void coloredtoBW(image * i,float alpha);

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
void RGBtoBW(uint64_t *pixel,int vmax,float alpha);

/**
 * \fn int readType(FILE *sourceFile, typeImage *type).
 * \brief Lit le type d'une image.
 *
 * \param[in] sourceFile Le fichier source à lire.
 * \param[out] type Le type de l'image.
 * \return EXIT_SUCCESS si ,sinon EXIT_FAILURE
 */
int readType(FILE *sourceFile, typeImage *type);

/**
 * \fn int readDimension(FILE *sourceFile, uint32_t *l, uint32_t *h)
 * \brief Lit les dimmensions d'une image dans le fichier source.
 *
 * \param[in] sourceFile Le fichier source à parcourir.
 * \param[out] l La largeur de l'image.
 * \param[out] h La hauteur de l'image.
 * \return EXIT_SUCCESS si ,sinon EXIT_FAILURE
 */
int readDimension(FILE *sourceFile, uint32_t *l, uint32_t *h);

/**
 * \fn int readMax(FILE *sourceFile,int *max)
 * \brief Lit la valeur max d'une image dans un fichier.
 *
 * \param[in] Le fichier dans lequel lire la valeur max.
 * \param[out] max La valeur max.
 * \return EXIT_SUCCESS si ,sinon EXIT_FAILURE
 */
int readMax(FILE *sourceFile,int *max);

/**
 * \fn void getColor(uint64_t const *pixel, uint16_t *r,uint16_t *g,uint16_t *b)
 * \brief Prend un entier sur 64 bit et retourne le (r,g,b) 
 *
 * \param[in] pixel L'entier correspondant à une couleur
 * \param[out] r La partie rouge du pixel.
 * \param[out] g La partie verte du pixel.
 * \param[out] b La partie bleu du pixel.
 */
void getColor(uint64_t const *pixel, uint16_t *r,uint16_t *g,uint16_t *b);

/**
 * \fn char * typeToString(typeImage type)
 * \brief Convertir un enum en chaine de caractére.
 *
 * \param[in] type Le type énuméré à convertir.
 * \return Une chaine de caractére qui représente le type.
 */
char * typeToString(typeImage type);

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
void usage();

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
void message(char * mess);

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
void verifppm(char * filename);

/**
 * \fn 
 * \brief 
 *
 * \param[in] 
 * \param[out] 
 * \return 
 */
char * modifExtention(char * sourceName,int option);

#endif
