/**********************************************************
 *	Author: Bombbeard
 * 	Filename: outputTest.c
 *	Date:	5/21/16
 *	Purpose: Write the given parameter to file.
 *********************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_FILENAME_LENGTH 50

/*	Basic flow:
	Generate string to write ->
	Open file ->
	Write to file ->
	Close file -X	*/
	
int main(int argc, char *argv[]){
	/*	Make sure your buffer is big enough to 
		handle whatever you plan to put in it...
		Giggity~	*/
	char buf[MAX_FILENAME_LENGTH];
	/*	FILE is a type, related to int, which holds
		a value that represents the location of an
		open file. We use a pointer to this value...
		Well, I'm not sure why quite yet. If I find out
		I will update somewhere.	*/
	FILE *fp;
	/*	fopen requires a char* that contains a char
		option. We use a char array of length 2 to 
		accomodate the null-terminator. The char 'a'
		opens a file in 'append' mode. This creates
		a file if one doesn't exist; if one does, it
		will append future write operations to the 
		end of the file, replacing the EOF character
		after each write operation.	*/
	char openOption[2] = "a";
	
	if( argc != 2 ){
		printf("Usage: <file name>\n");
		return(1);
	}
	/*	sprintf formats a string and assigns it to the 
		first parameter	*/
	sprintf(buf, "%s\n",argv[1]);
	printf("%s",buf);
	/*	If this open operation fails and we attempt to
		write, our program will crash. We must check
		for this condition and do something in response.
		This time I close the program, but you could
		easily loop back for another input and subsequent
		attempt at opening. 
		Additionally, the function fopen() returns a 
		pointer to the opened file, which we need for
		performing write operations later.	*/
	if( (fp = fopen( "test.txt", openOption) ) == NULL ){return(1);}
	/*	The big payoff: the write operation. fputs()
		writes entire strings, up to but not including
		the null-terminator, to a given file.	*/
	fputs(buf, fp);
	/*	close file	*/
	/*	ALWAYS close your file! This can be the 
		cause of major headaches later when you can't
		access a given file for seemingly no reason.	*/
	fclose( fp );
	
	return 0;
}
