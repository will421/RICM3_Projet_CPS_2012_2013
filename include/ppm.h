/**
 * \file ppm.h
 * \brief Operations spécifiques aux images PPM.
 * \author Corentin RICOU et William BOBO
 * \version 1
 * \date 11 avil 2013
 */

#ifndef PPM_H
#define PPM_H

#include "util.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/**
 * \fn int readPixelppm(FILE *sourceFile, uint64_t *pixel)
 * \brief 
 *
 * \param[in] sourceFile Le fichier PPM duquel on lit un pixel.
 * \param[out] pixel L'entier correspondant à la couleur du pixel lu dans le fichier
 * \return EXIT_SUCCESS si , EXIT_FAILURE sinon.
 */
int readPixelppm(FILE *sourceFile, uint64_t *pixel);

/**
 * \fn int readDatappm(FILE *sourceFile,image *img)
 * \brief Lit toute la partie data du fichier ppm et la met dans "data" de img
 *
 * \param[out] sourceFile Le fichier ppm à lire.
 * \param[in] img l'image à remplir avec la partie data.
 * \return EXIT_SUCCESS si , EXIT_FAILURE sinon.
 */
int readDatappm(FILE *sourceFile,image *img);

/**
 * \fn image* readppm(FILE *sourceFile)
 * \brief Lit un fichier ppm, créé une structure image et la remplit.
 *
 * \param[in] sourceFile Le fichier ppm à lire.
 * \return Un pointeur sur l'image créé lors de la lecture ou null sinon 
 */
image* readppm(FILE *sourceFile);

/**
 * \fn image* readppmIn(FILE *sourceFile)
 * \brief Lit un fichier ppm sur l'entré standard
 *
 * \param[in] sourceFile Le fichier ppm à lire.
 * \return Un pointeur sur l'image créé lors de la lecture ou null sinon 
 */
image* readppmIn();

#endif
