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
	listS* HEAD = (listS*)malloc(sizeof(listS));
	//assert(HEAD);
	HEAD->head = NULL;
	return HEAD;
}

// Funkcja dodawania elementu
int push (listS* head_init, int dane)
{
	if (head_init->head == NULL)
	{
		head_init->head = (nodeS*)malloc(sizeof(nodeS));
		head_init->head->data = dane;
		head_init->head->next_Node = NULL;
		return 0;
	}

	nodeS* current_ptr = head_init->head;

	while(current_ptr->next_Node != NULL)
	{
		current_ptr = current_ptr->next_Node;
	}
		current_ptr->next_Node = (nodeS*)malloc(sizeof(nodeS));
		current_ptr->next_Node->data = dane;
		current_ptr = current_ptr->next_Node;
		current_ptr->next_Node = NULL;
		return 0;
}
// Usuwanie pierwszego węzła listy
int pop_front(listS* head_init, int* value)
{
	if(head_init->head == NULL)
	{
		return -1;
	}

	nodeS* current_ptr = head_init->head;  //dereferencja head'a, aby uzyskać jego obecną postać
	*value = head_init->head->data;
	head_init->head = head_init->head->next_Node;
	free(current_ptr);
	current_ptr = NULL;

	return 0;
}

// Usuwanie ostatniego węzła listy
int pop_back(listS* head_init, int* value)
{
	if (head_init->head == NULL) //0 node
	{
		return -1;
	}

	nodeS* current_ptr = head_init->head;
	nodeS* next_ptr = current_ptr->next_Node;
	//nodeS* next_ptr = head_init->head->next_Node;

	if (head_init->head->next_Node == NULL) //1 node
		{
			free(current_ptr);
			next_ptr->next_Node = NULL;
			return 0;
		}

	while (next_ptr->next_Node != NULL)
	{
		next_ptr = next_ptr->next_Node;
		current_ptr = current_ptr->next_Node;
	}

	*value = next_ptr->data;
	free(next_ptr);
	current_ptr->next_Node = NULL;
	return 0;
}

// Drukowanie danych i adresu węzłow listy
int print(listS* head_init)
{
	if (head_init->head == NULL)
	{
		printf(" Lista jest pusta");
		return -1;
	}

	nodeS* current_ptr = head_init->head;

	while (current_ptr != NULL)
	{
		nodeS* next_ptr = current_ptr->next_Node;
		printf("Wartosc Node'a =  %d\n", current_ptr->data);
		printf("Adres Node'a   = %p\n", current_ptr->next_Node);
		current_ptr = next_ptr;
	}
	return 0;
}

// Czyszczenie listy
int clear(listS* head_init)
{
	if (head_init->head == NULL)
	{
		return -1;
	}

	nodeS* current_ptr = head_init->head;

	while (current_ptr!= NULL)
	{
		nodeS* next_ptr = current_ptr->next_Node;
		//nodeS* next_ptr = head_init->head;
		free(current_ptr);
		current_ptr = next_ptr;
	}

	head_init->head = NULL;
	//free(head_init);
	return 0;
}





