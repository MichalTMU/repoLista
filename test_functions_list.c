#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions_list.h"
#include <criterion/criterion.h>

/*  Test funkcji clear  */
Test(test, clear_list)
{
	int value_test = 3;
	listS* HEAD = init();
	push(HEAD, value_test);
	push(HEAD, value_test);
	push(HEAD, value_test);
	clear(HEAD);

	cr_assert_null(HEAD->head, "Lista nie jest zakończona Null'em");
	free(HEAD);
}

/*  Test funkcji init  */
Test(test, function_init_list)
{
	int value_test = 5;
	listS* HEAD = init();
	push(HEAD, value_test);
	clear(HEAD);
	free(HEAD);
}

/*   Test funkcji push    */
Test(test, push_node)
{
	int value_test = 5;
	listS* HEAD = (listS*)malloc(sizeof(listS*));
	HEAD->head = NULL;
	push(HEAD, value_test);
	cr_expect(HEAD->head->data == value_test);
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

	for (int i=0; i<6; i++)
	{
		push(HEAD,i*value_test);
		pop_front(HEAD, &data);
		clear(HEAD);
	}
	cr_assert_null(HEAD->head,"HEAD nie wskazuje na Null'a po wykonaniu tylu pop'ów ile push'ów");
	free(HEAD);
}
