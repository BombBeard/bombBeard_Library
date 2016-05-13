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

/****************  Description  ****************
 *
 **********************************************/
 
#include <stdio.h>

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