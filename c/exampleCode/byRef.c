/************************************************
 *	Filename:		byRef.c
 *	Author:			BombBeard
 *	Date:			5/12/16
 *	Language:		C
 *
 *	Reachable at:	
 *		email:		bombBeardGaming@gmail.com
 *		youtube:	http://bit.ly/1lp2hUw
 *		twitch:		twitch.tv/bombbeard
 * 		twitter:	@bombBeard
 ************************************************/
 
/*******************  Description  ************************
 *	Functions can have parameters declared in one of 2 ways:
 *	By Value & By Reference. We refer to this as 
 *	"passing by value" and "passing by reference." When you
 *	pass by reference you are passing an address, or the 
 *	location in memory where the value of the variable is 
 *	stored. 
 *
 *	Because of this, we can affect the passed variable directly
 *	from within a given function. This is different than 
 *	passing by value where the passed parameter is copied to
 *	a locally declared variable. (See scope.c for information 
 *	about scope.)
 *
 *	C implements this concept by defining parameters as pointers
 *	and requiring either a proper pointer variable or the 
 *	address of a variable (see pointer.c for more information
 *	about pointers.)
 *********************************************************/

#include <stdio.h>

void add( int *var1, int var2 ){
	/*	During declaration of a variable or in a function's parameters,
		the * operator makes the variable/parameter a pointer.
		A pointer "points" to where in memory the value or the 
		variable is stored.	*/

	printf("add() variables:\t var1 = %i\tvar2 = %i\n", var1, var2);
	printf("add() variables:\t *var1 = %i\t\n\n", var2);
	
	/*	the * operator returns the value stored at the given address	*/	
	*var1 = *var1 + var2;	/*	x holds the addition of x and y	*/
}


int main(){
	int x = 10;
	int y = 3;
	
	printf("Before add()\n");
	printf("x:\t%i\nY:\t%i\n\n",x,y);	
	
	printf("After add()\n");
	printf("x:\t%i\nY:\t%i\n",x,y);	
	
	return 0;
}