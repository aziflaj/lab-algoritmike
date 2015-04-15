#
# Make the code for the 2nd task of the Lab
#

COMPILE = gcc -std=c99 -Ilibs
MAIN_FILES = src/app.c src/text.c libs/utils.c
TEST_FILES = tests/test.c libs/utils.c

all:
	$(RM) *.exe
	
	#
	# Compile below
	# $(CC) $(LFLAGS) -std=c99 $(MAIN_FILES) -o app
	$(COMPILE) $(MAIN_FILES) -o app
	
	printf "\n"
	printf "***********\n"
	printf "*** END ***\n"
	printf "***********"
	printf "\n"


test:
	#$(RM) tests/*.exe

	#
	# Compile below
	$(COMPILE) $(TEST_FILES) -o test
	
	printf "\n"
	printf "*********************\n"
	printf "*** READY TO TEST ***\n"
	printf "*********************"
	printf "\n"


clean:
	$(RM) *.exe
	$(RM) tests/*.exe

.SILENT: all test clean
.PHONY: all test clean