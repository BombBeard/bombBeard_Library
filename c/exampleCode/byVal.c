/******************************************************
 *	Filename:		byVal.c
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

/*******************  Description  ************************
 *	Functions can have parameters declared in one of 2 ways:
 *	By Value & By Reference. We refer to this as 
 *	"passing by value" and "passing by reference." When you
 *	pass by value, you are declaring local variables within
 *	your function (see scope.c for more information about 
 *	scope) and copying the value of the parameter to that 
 *	variable.
 *	
 *	This can be useful for "low-cost" types, such as primitives
 *	(think: int, char, long) or types with few data fields,
 *	as a means of not mistakenly altering a given variable.
 *	A more practical reason pass by value is to simplify
 *	the syntax, which generally reduces errors. Generally 
 *	speaking, pass by reference is a more cost-effective
 *	means of passing parameters, as many objects can be large
 *	and copying the entire contents can be unreasonable.
 *********************************************************/
 
#include <stdio.h>

int add( int var1, int var2 ){		/*	functions of type int require a return of type int	*/
	/*	variables x and y have had their values copied to the local copies
		which are labeled as var1 and var2.	*/

		printf("add() variables:\t var1 = %i\tvar2 = %i\n\n", var1, var2);

	return var1 + var2;
}


int main(){
	int x = 10;
	int y = 3;
	
	printf("Before add()\n");
	printf("x:\t%i\nY:\t%i\n\n",x,y);	
	
	/*	add(x, y) returns an integer, which is used as an argument in printf	*/
	printf("add( x, y ) == %i\n\n", add(x, y) );
	
	printf("After add()\n");
	printf("x:\t%i\nY:\t%i\n",x,y);	
	
	return 0;
}