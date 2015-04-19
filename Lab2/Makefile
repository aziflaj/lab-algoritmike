#
# Make the code for the 2nd task of the Lab
#

CC = gcc 
FLAGS = -std=c99 -Ilibs -Isrc
MAIN_FILES = src/app.c src/text.c
TEST_FILES = tests/runtests.c

all:
	$(RM) tests/*.exe
	$(RM) libs/*.exe
	$(RM) src/*.exe
	$(RM) *.exe
	
	$(CC) $(FLAGS) $(MAIN_FILES) -o app

	printf "\n"	
	printf "*********************\n"
	printf "*** READY TO EXEC ***\n"
	printf "*********************"
	printf "\n"


test:
	$(CC) $(FLAGS) $(TEST_FILES) -o test
	
	printf "\n"
	printf "*********************\n"
	printf "*** READY TO TEST ***\n"
	printf "*********************"
	printf "\n"


clean:
	$(RM) tests/*.exe
	$(RM) libs/*.exe
	$(RM) src/*.exe
	$(RM) *.exe

.SILENT: all test clean
.PHONY: all test clean