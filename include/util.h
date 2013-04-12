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

/**
 * \fn void trace(char * message);
 * \bried Raccourci pour afficher des messages rapides lors du debugage
 *
 * \param[in] message Le message à afficher précédé de "trace :"
void trace(char * message);

/**
 * \fn void coloredtogray(image * i,float a,float b,float c);
 * \brief Convert une image de couleur en une image en nuance de gris
 *
 * \param[in] image L'image à modifier
 * \param[in] a definit l'importance du rouge
 * \param[in] b definit l'importance du vert
 * \param[in] c definit l'importance du bleu
 * \param[out] image L'image modifié en gris
 */
void coloredtogray(image * i,float a,float b,float c);

/**
 * \fn void RGBtoGrey(uint64_t *pixel,float a,float b,float c)
 * \brief Convertit un pixel de couleur en un pixel gris
 *
 * \param[in] pixel le pixel à modifier
 * \param[in] a definit l'importance du rouge
 * \param[in] b definit l'importance du vert
 * \param[in] c definit l'importance du bleu
 * \param[out] pixel le pixel modifié en gris
 */
void RGBtoGrey(uint64_t *pixel,float a,float b,float c);

/**
 * \fn void coloredtoBW(image * i,float alpha)
 * \brief Convertit une image ppm en une image noir et blanc
 *
 * \param[in] image L'image à modifier
 * \param[in] alpha Definit à partir de quel intensité passer en noir ou blanc
 * \param[out] image L'image modifié en noir et blanc
 */
void coloredtoBW(image * i,float alpha);

/**
 * \fn void RGBtoBW(uint64_t *pixel,int vmax,float alpha
 * \brief Convertit un pixel coloré en un pixel noir ou blanc
 *
 * \param[in] pixel le pixel à modifier
 * \param[in] vmax La valeur que ne doit pas depasser le pixel
 * \param[in] alpha Definit à partir de quel intensité passer en noir ou blanc
 * \param[out] pixel le pixel modifié
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
 * \fn void usage();
 * \brief Affiche l'usage de traitement_image
 *
 */
void usage();

/**
 * \fn void message(char * mess)
 * \brief Affiche des message informatifs
 *
 * \param[in] mess Le message à affiché
 * \return 
 */
void message(char * mess);

/**
 * \fn void verifppm(char * filename);
 * \brief Verifie si le nom de fichier donnée en entrée est bien un .ppm. Quitte le programme dans le cas contraire
 *
 * \param[in] filename le nom du fichier
 */
void verifppm(char * filename);

/**
 * \fn char * modifExtention(char * sourceName,int option)
 * \brief Utilise sourceName, modifier son extention pour en faire un pgm ou ppm selon l'option et retourne une nouvelle chaine
 *
 * \param[in] sourceName Le nom du fichier ppm source
 * \param[in] option Definit si le fichier destination doit etre un pbm ou ppm
 * \return retourne un pointeur sur une nouvelle chaine de charactere contenant le nouveau nom (.pgm ou .ppm)
 */
char * modifExtention(char * sourceName,int option);

#endif
