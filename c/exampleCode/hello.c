#include <stdio.h>		/*	declares printf()	*/
#include <unistd.h>		/*	declares write()	*/

/*	Here are 3 ways to implement Hello World.

	The string literal way is by far the simplest to explain
	and understand. Simply type a string literal as a parameter
	for printf() and call it a day!
	
	The variable version introduces a char[] to store whatever
	string you want to print. Using a variable to print allows 
	you to change the variable and have any following uses of 
	it be changed as well.
	
	**	Don't worry too much about this version; it is only
		if you are overly curious or bored with the previous
		2 versions.	**
	Lastly, the horrendous version makes use of the system call
	write() which directly writes to the screen. It takes a 
	file descriptor (in this case 1, for standard output),
	a void* reference to what you want to print,
	and the number of bytes away from the pointer you supplied
	you are allowing it to write.
	
	The goal here is to show that for any problem, there are 
	many ways to solve them. These resolutions range from simple
	to highly specialized.
	
*/
	

int main(){
	
	/*	String Literal Version	*/
	/*		Useful for simple, one time print statements	*/
	
	printf("Hello World!\n");
	
	/*	End	*/
	
	/*	Variable Version	*/
	/*		Useful for debugging or for runtime-based print-statements.
			That is to say that if you don't know ahead of time what a 
			value you want to print will be, using a variable to print
			allows you to assign that unknown value and print it.	*/
			
	// char hello[] = {"Hello world!\n"};
	// printf("%s\n",hello);
	
	/*	End	*/
	
	
	/*	Horrendous Version	*/
	/*		Useful when a buffered output is unwanted, or when concerned
			about asyncronous events.	*/
			
	// char help[] = {"Hello World!\n"};
	/*	13 normal chars + 1 null terminator	*/
	// int numChars = 14, i = 0;	
	
	// while(i++ < numChars){
		// write( 1, (void*) help[i], 0);
		/*	Not a fan of void* casts but alas, the library
			demands it	*/
		// printf("%s",help[i]);
	// }
	// printf("\n");
	/*	printf( STRING, ...ARGS ) takes a string
		with format descriptors, and arguments
		to insert to those format descriptors	*/
	
	/*	End	*/
	
	return 0;
	
}