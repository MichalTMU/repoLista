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

// head_init
listS* init()
{
	listS* HEAD = (listS*)malloc(sizeof(listS)); 	// alokuje węzeł do sterty
	assert(HEAD);
	HEAD->head = NULL;
	return HEAD;
}

// Dokładanie kolejnego węzła(Noda)
int push (listS* head_init, int dane)
{
		// tworzę zmienna lokalną, która wskazuje na pierwszy element listy(head)
	if (head_init->head == NULL)
	{
		head_init->head = malloc(sizeof(nodeS)); //alokuję węzeł do sterty (head)
		head_init->head->data = dane; 			// przypisuje dane w pierwszym węźle
		head_init->head->next_Node = NULL; 		// alokuje następny węzeł do sterty
		return 0;
	}

	nodeS* current_ptr = head_init->head;
	while(current_ptr->next_Node != NULL) 		// zwraca false jeśli current_ptr jest Null'em. True jeśli jest inny.
	{
		current_ptr = current_ptr->next_Node;
	}
		current_ptr->next_Node = malloc(sizeof(nodeS));
		current_ptr->next_Node->data = dane;
		current_ptr = current_ptr->next_Node;
		current_ptr->next_Node = NULL;

		return 0;
		//current_ptr->next_Node   //current_ptr wskazuje element listy. wyrażenie current_ptr->next zwraca wartość next obiektu.
}

// Usuwanie pierwszego węzła listy
int pop_front(listS* head_init)
{
	//gdy po headzie nie ma żadnego węzła(pusta lista)
	if(head_init->head == NULL)
	{
		printf("Nic tu nie ma");
		return 0;
	}
	nodeS* current_ptr = head_init->head;  //dereferencja head'a, aby uzyskać jego obecną postać
	head_init->head = head_init->head->next_Node;
	free(current_ptr);
	current_ptr = NULL;

	return 0;
}

// Usuwanie ostatniego węzła listy
int pop_back(listS* head_init)
{
	//gdy po headzie nie ma żadnego węzła(pusta lista)
	if (head_init->head == NULL)
	{
		printf("Nic tu nie ma");
		return 0;
	}
	nodeS* current_ptr = head_init->head;	      //dereferencja head'a, aby uzyskać jego obecną postać
	nodeS* next_ptr = head_init->head->next_Node; //dereferencja nastepnego wezła

	while (next_ptr->next_Node != NULL) 	 	  // zwraca false jeśli next_ptr jest Null'em, True jesli ma inna wartosc
	{
		next_ptr = next_ptr->next_Node;
		current_ptr = current_ptr->next_Node;
	}
	if (head_init->head->next_Node == NULL)
	{
		free(current_ptr);
		next_ptr->next_Node = NULL;
		return 0;
	}
	free(next_ptr);
	current_ptr->next_Node = NULL;
	return 0;
}

// Drukowanie danych i adresu węzłow listy
int print(listS* head_init)
{
	// wskaźnik current_ptr węzeł który obecnie drukujemy. Gdy wydrukuje wartość danego węzła, przechodzimy
	//  do następnego węzła i drukujemy jego wartość i tak dopóki nie dojdziemy do NULLa.

	if (head_init->head == NULL)
	{
		printf("Lista jest pusta");
		return 1;
	}

	nodeS* current_ptr = head_init->head;
	while (current_ptr != NULL) // zwraca false jeśli current_ptr jest Null'em. True jeśli jest inny.
	{
		nodeS* next_ptr = current_ptr->next_Node;
		printf("Wartosc Node'a =  %d\n", current_ptr->data);
		printf("Adres Node'a   = %p\n",current_ptr->next_Node);
		current_ptr = next_ptr;
	}
	return 0;
}

// Czyszczenie listy
int clear(listS* head_init)
{
	nodeS* current_ptr = head_init->head; //dereferencja Head'a, aby uzyskać jego obecną postać

	while (current_ptr != NULL)  //zwraca false jeśli current_ptr jest Null'em. True jeśli jest inny.
	{
		nodeS* next_ptr = current_ptr->next_Node;
		//nodeS* next_ptr = head_init->head;
		free(current_ptr);
		current_ptr = next_ptr;
	}
	return 0;
}





