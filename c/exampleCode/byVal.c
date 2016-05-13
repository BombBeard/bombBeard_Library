#include <stdio.h>

void add( int x, int y ){		/*	functions of type void don't return	*/
	/*	x holds the addition of x and y	*/
	
	int value;
	value = x + y;				/*	the * operator returns the value stored
									at the given address	*/
	return value;
}


int main(){
	int x = 10;
	int y = 3;
	
	printf("Before add()\n");
	printf("x:\t%i\nY:\t%i\n\n",x,y);	/*	before add()	*/
	add( x, y );
	printf("After add()\n");
	printf("x:\t%i\nY:\t%i\n",x,y);	/*	after add()	*/
	
	return 0;
}