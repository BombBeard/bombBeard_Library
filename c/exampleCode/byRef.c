#include <stdio.h>

void add( int *var1, int var2 ){		/*	functions of type void don't return	*/
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