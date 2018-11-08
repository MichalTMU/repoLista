#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions_list.h"
#include <criterion/criterion.h>

int main(void)
{
	int valueMain = 0;
	listS* HEAD = init();
	push(HEAD, 2);
	push(HEAD, 4);
	push(HEAD, 8);
	push(HEAD, 11);
	push(HEAD, 12);
	push(HEAD, 14);

	pop_front(HEAD, &valueMain);
	printf("Dane z pierwszego Noda po wykonaniu pop_front'a = %d\n", valueMain);

	pop_back(HEAD, &valueMain);
	printf("Dane z ostatniego Noda po wykonianiu pop_back'a = %d\n", valueMain);

	print(HEAD);
	clear(HEAD);
	free(HEAD);
	return 0;
}
