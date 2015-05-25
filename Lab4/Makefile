#
# Makefile for Lab4
#

CC = gcc

MAIN_FILES = src/app.c src/bst.c
FLAGS = -std=c99 

all:
	$(RM) app
	$(RM) *.exe

	$(CC) $(FLAGS) $(MAIN_FILES) -o app

	printf "\n"	
	printf "*********************\n"
	printf "*** READY TO EXEC ***\n"
	printf "*********************"
	printf "\n"

clean:
	$(RM) app
	$(RM) *.exe

.SILENT: all test clean
.PHONY: all test clean