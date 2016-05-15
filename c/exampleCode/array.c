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
 
 #include <stdio.h>
 #include <unistd.h>
 
int main(){

	char name[] = {"Charlie"};
	/* Holds the 3rd character of name */
	char c = name[2];

	printf("name[2] (char flag):\t%c\n",name[2]);
	/* name + 2 is taking the address from name and adding
	 * 2 bytes to the address value. 
	 * We then take that address and write 1 byte to stdout
	 * This is intended to show the relationship between 
	 * indexes of arrays and their addresses. */
	printf("name + 2 (write):\t");
	write( 1, name+2, 1);
	printf("\n");

	return 0;
}