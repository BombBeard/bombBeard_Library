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