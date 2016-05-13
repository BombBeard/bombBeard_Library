#include <stdio.h>

int add( int var1, int var2 ){		/*	functions of type void don't return	*/
	/*	x and y are declared in function scope, and are referred to 
		as local variables.
		This causes the variable labels x and y declared in main 
		to be shadowed 
		these variables.	*/
	int x = 30, y = 50;

	return x + y;
}


int main(){
	int x = 10;
	int y = 3;
	
	printf("Before add()\n");
	printf("x:\t%i\nY:\t%i\n\n",x,y);	/*	before add()	*/
	
	printf("add( x, y ) == %i\n\n", add(x, y) );
	
	printf("After add()\n");
	printf("x:\t%i\nY:\t%i\n",x,y);	/*	after add()	*/
	
	return 0;
}