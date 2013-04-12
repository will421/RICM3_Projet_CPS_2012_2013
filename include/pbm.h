/**
 * \file pbm.h
 * \brief Operations spécifiques aux images PBM.
 * \author Corentin RICOU et William BOBO
 * \version 1
 * \date 11 avril 2013
 */

#ifndef PBM_H
#define PBM_H

#include "util.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/**
 * \fn int endsWith(const char * str, const char *suffix);
 * \brief  
 *
 * \param[in] str Chaine complête à vérifier.
 * \param[in] suffix Chaîne représentant un suffixe.
 * \return 0 si str se termine par suffix, 1 sinon.
 */
int writepbm(FILE * destFile, image* img);

#endif
