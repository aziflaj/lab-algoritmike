#
# Make the code for the 1st task of the Lab
#

CC = gcc
MAKE = mingw32-make

all:
	$(MAKE) clean
	$(CC) app.c trace.c -o app
	
	printf "\n"
	printf "***********"
	printf "\n*** END ***\n"
	printf "***********"
	printf "\n"

clean:
	$(RM) *.exe
	$(RM) ../static/simone.txt
	$(RM) ../static/simtwo.txt

.SILENT: all clean