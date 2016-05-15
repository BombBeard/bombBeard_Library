/******************************************************
 *	Filename:		scope.c
 *	Author:			BombBeard
 *	Date:			5/12/16
 *	Language:		C
 *
 *	Reachable at:	
 *		email:		bombBeardGaming@gmail.com
 *		youtube:	http://bit.ly/1lp2hUw
 *		twitch:		twitch.tv/bombbeard
 * 		twitter:	@bombBeard
 ******************************************************/

/*********************  Description  **********************
 *	Pointers are variables which point to the address in 
 *	memory of the given variable. Pointer variables have
 *	a type which helps to show what type of data is being
 *	pointed to.
 *
 *	&:	"address of" operator. Returns the address of a 
 *		given variable.
 *	*:	"reference/dereference" operator. Return value 
 *		depends on the context of usage{
 *			During declaration:	creates a pointer variable.
 *			Anywhere else:	returns the value stored at the
 *				pointed to address
 *		}
 *	The concept of pointers is associated closely with
 *	arrays ( see array.c for more information. )
 *********************************************************/

#include <stdio.h>
#include <unistd.h>
 
 int main(){
	/* holds the value 0 */
	int sumNum = 0;		
	/* holds the address of sumNum */
	int *sNPtr = &sumNum;	
	
	/* Points to where the 'C' is stored in memory.
	 * Note that name is pointing to the first index
	 * of memory, but is considered an array of 
	 * characters, and not just a pointer. */
	char name[] = {"Charlie"};
	/* Holds the 3rd character of name */
	char c = name[2];
	
	/* assigning 10 to sumNum is valid */
	sumNum = 10;
	/* assigning 10 to sNPTR is also valid...
	 * but will result in pointing to memory location
	 * 10, which is reserved, and will cause a segmentation
	 * fault crashing your program. */
	sNPtr = (void*)10;
	/* let's assign sNPtr the address of sumNum again to
	 * prevent this issue. */
	sNPtr = &sumNum;
	
	/* Let's start printing ALL THE THINGS */
	printf("sumNum:\t%i\n",sumNum);
	printf("sNPtr:\t%p\n",sNPtr);
	printf("*SNPtr:\t%i\n",*sNPtr);
	printf("name (string flag):\t%s\n",name);
	printf("name (pointer flag):\t%p\n",name);
	printf("name + 2 (pointer flag):%p\n",(name+2));
	printf("c (char flag):\t\t%c\n",c);
	printf("c (pointer flag):\t%p\n",c);
	
 }
 
 /******************  Related Material  *******************
 *	
 *********************************************************/