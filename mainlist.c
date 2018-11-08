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

	pop_front(HEAD, &valueMain); //usuwam pierwszego węzeł(2)
	printf("Dane z pierwszego Noda po wykonaniu pop_front'a = %d\n", valueMain);

	pop_back(HEAD, &valueMain);  // usuwam ostatni węzeł (14)
	printf("Dane z ostatniego Noda po wykonianiu pop_back'a = %d\n", valueMain);

	print(HEAD);
	clear(HEAD);
	free(HEAD);
	return 0;
}


/*     TESTY     */

/*  Test funkcji clear  */
Test(test, clear_list)
{
	listS* HEAD = init();
	push(HEAD, 5);
	push(HEAD, 4);
	push(HEAD, 4);
	clear(HEAD);

	cr_assert_null(HEAD->head, "Lista nie jest zakończona Null'em");
	free(HEAD);
}

/*  Test funkcji init  */
Test(test, function_init_list)
{
	listS* HEAD = init();
	push(HEAD, 4);
	clear(HEAD);
	free(HEAD);
}

/*   Test funkcji push    */
Test(test, push_node)
{
	listS* HEAD = (listS*)malloc(sizeof(listS*));
	HEAD->head = NULL;
	push(HEAD, 3);
	cr_expect(HEAD->head->data == 3);
	clear(HEAD);
	free(HEAD);
}


/*  Test funkcji pop_front  */
Test (test, pop_front_node)
{
	listS* HEAD = init();
	int value_test = 3;
	int add = 0;

	push(HEAD, value_test);
	pop_front(HEAD, &add);

	cr_assert_null(HEAD->head,"Head kończy się Null'em");
	free(HEAD);
}


/*  Test funkcji pop */
Test (test, pop_nodes)
{
	listS* HEAD = init();
	int data = 0;
	int value_test = 3;

	for(int i=0; i<6; i++)
	{
		push(HEAD,i*value_test);
		pop_front(HEAD, &data);
		clear(HEAD);
	}
	cr_assert_null(HEAD->head,"HEAD nie wskazuje na Null'a po wykonaniu tylu pop'ów ile push'ów");
	free(HEAD);
}
