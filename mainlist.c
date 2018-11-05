/*
 ============================================================================
 Name        : mainlist.c
 Author      : Michal
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions_list.h"


int main(void)
{
	listS* HEAD = init();
	push(HEAD, 2);
	push(HEAD, 4);
	push(HEAD, 8);
	push(HEAD, 11);
	push(HEAD, 12);
	push(HEAD, 14);

	pop_front(HEAD); //usuwam pierwszego węzeł(2)
	pop_back(HEAD);  // usuwam ostatni węzeł (14)

	print(HEAD);
	clear(HEAD);
	return 0;
}




