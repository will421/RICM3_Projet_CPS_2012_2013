
#########################################
########### LES VARIABLES ###############

# La racine du projet
# Warning => ne pas utiliser la variable PATH elle est réservé.
DPATH = .
#------------------------------------------
# Variables pour le traitement des images
DSRC = $(DPATH)/src
DBIN = $(DPATH)/bin
DINC = $(DPATH)/include
DDOC = $(DPATH)/doc
DOBJ = $(DPATH)/obj

EXEC=traitement_image
SRC= $(wildcard $(DSRC)/*.c)
OBJ= $(SRC:$(DSRC)/%.c=$(DOBJ)/%.o)

#------------------------------------------
# Variables pour les tests 
TDSRC = $(DPATH)/test/src
TDBIN = $(DPATH)/test/bin
TDOBJ = $(DPATH)/test/obj
TDINC = $(DPATH)/test/include

TEXEC= test
TSRC= $(wildcard $(TDSRC)/*.c)
TOBJ= $(TSRC:$(TDSRC)/%.c=$(TDOBJ)/%.o)

#------------------------------------------
# OPTIONS DE COMPILATION
CC=gcc
CFLAGS=-g -std=c90 -pedantic -Wall -Wextra
LDFLAGS=

#########################################
############ LES REGLES #################
all: traitement_image test
traitement_image: $(DBIN)/$(EXEC)
test: $(TDBIN)/$(TEXEC)

#****************************************
# Régles pour le traitement des images
$(DBIN)/$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)/*.h
	$(CC) -o $@ -c $< $(CFLAGS) -I$(DINC)

#****************************************
# Régles pour les tests
$(TDBIN)/$(TEXEC): $(TOBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
$(TDOBJ)/%.o: $(TDSRC)/%.c $(TDINC)/*.h
	$(CC) -o $@ -c $< $(CFLAGS) -I$(TDINC)

.PHONY: mrproper-traitement mrproper-test clean-traitement clean-test

#****************************************
# CLEAN
#
# On définit deux clean, un pour le projet et l'autre pour les tests
clean: clean-traitement clean-test
# Clean pour les fichiers de traitement des images
clean-traitement:
	rm -rf $(DOBJ)/*.o 
#clean pour les fichiers de test
clean-test:
	rm -rf $(TDOBJ)/*.o

#****************************************
# PROPER
#
# On définit deux mrproper, un pour le projet et l'autre pour les tests
mrproper: mrproper-traitement mrproper-test
# mrproper pour les fichiers de traitement des images
mrproper-traitement: clean-traitement
	rm -rf $(EXEC)
#mrproper pour les fichiers de test
mrproper-test: clean-test
	rm -rf $(TEXEC)
