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
 *	Where you declare something is what determines its' 
 *	default scope. Things declared outside of any functions
 *	are considered to have file scope. By contrast, things
 *	declared in any given function are considered to have
 *	a corresponding function-level scope. This leads to the
 *	concept of parameters. Only what is declared as file
 *	scope or declared in the function are known to the function.
 *	Parameters are local variables intialized with the values
 *	passed during the function call.
 *********************************************************/
 
#include <stdio.h>

char fileScopeVar[] = {"I can be seen by anything declared in \
	this file"};	/* that trailing '\' lets us continue down here */
	
/*	Since this is declared outside of any "{}"'s it has file-scope	*/

int add( int var1, int var2 ){		/*	functions of type int require a return of type int	*/
/*	x and y are declared in function scope, and are referred to 
	as local variables.
	This causes the variable labels x and y declared in main 
	to be shadowed by the variables declared locally.	*/

	int x = 30, y = 50;
	
	printf("add() variables:\t x = %i\ty = %i\n\n", x, y);

	return x + y;
}


int main(){
	int x = 10;
	int y = 3;
	
	printf("Before add()\n");
	printf("x:\t%i\nY:\t%i\n\n",x,y);
	
	printf("add( x, y ) == %i\n\n", add(x, y) );
	
	printf("After add()\n");
	printf("x:\t%i\nY:\t%i\n",x,y);
	
	return 0;
}

/******************  Related Material  *******************
 *	
 *********************************************************/