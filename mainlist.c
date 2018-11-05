/*
 ============================================================================
 Name        : mainlist.c
 Author      : Michal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
	{
	int data;
	struct node* next_Node;
	} node;

typedef struct list
	{
	node* head;
	} list;

// Stworzone funkcje
list* init();
int push (list* head_init, int dane);
int pop_front(list* head_init);
int pop_back(list* head_init);
int print (list* head_init);
int clear (list* head_init);


//head_init
list* init()
{
	list* HEAD = (list*)malloc(sizeof(list)); // alokuje węzeł do sterty
	assert(HEAD);
	HEAD->head = NULL;
	return HEAD;
}

// Dokładanie kolejnego węzła(Noda)
int push (list* head_init, int dane)
{
	// tworzę zmienna lokalną, która wskazuje na pierwszy element listy(head)
	if (head_init->head == NULL)
	{
		head_init->head = malloc(sizeof(node)); //alokuję węzeł do sterty (head)
		head_init->head->data = dane; // przypisuje dane w pierwszym węźle
		head_init->head->next_Node = NULL; // alokuje następny węzeł do sterty
		return 0;
	}

	node* current_ptr = head_init->head;
	while(current_ptr->next_Node != NULL) // zwraca false jeśli current_ptr jest Null'em. True jeśli jest inny.
	{
		current_ptr = current_ptr->next_Node;
	}
		current_ptr->next_Node = malloc(sizeof(node));
		current_ptr->next_Node->data = dane;
		current_ptr = current_ptr->next_Node;
		current_ptr->next_Node = NULL;

		return 0;
}
	// musimy ustawić Null'a na ostatnim next'cie jesli chcemy zakończyć przechodzenie do następnego elementu

// Usuwanie pierwszego węzła
int pop_front(list* head_init)
{
	//gdy po headzie nie ma żadnego węzła(pusta lista)
	if(head_init->head == NULL)
	{
		printf("NIE MA TU NIC");
		return 0;
	}
	node* current_ptr = head_init->head;
	head_init->head = head_init->head->next_Node;
	free(current_ptr);
	current_ptr = NULL;

	return 0;
}

// Usuwanie ostatniego węzła listy
int pop_back(list* head_init)
{
	//gdy po headzie nie ma żadnego węzła(pusta lista)
	if (head_init->head == NULL)
	{
		printf("NIC TU NIE MA");
		return 0;
	}
}

int clear(list* head_init)
{
	node* current_ptr = head_init->head; //dereferencja Head'a, aby uzyskać jego obecną postać

	while (current_ptr != NULL)  //zwraca false jeśli current_ptr jest Null'em. True jeśli jest inny.
	{
		node* next_ptr = current_ptr->next_Node;
		//node* next_ptr = head_init->head;
		free(current_ptr);
		current_ptr = next_ptr;
	}
	return 0;
}

int print(list* head_init)
{
	// wskaźnik current_ptr węzeł który obecnie drukujemy. Gdy wydrukuje wartość danego węzła, przechodzimy
	//  do następnego węzła i drukujemy jego wartość i tak dopóki nie dojdziemy do NULLa.

	if (head_init->head == NULL)
	{
		printf("Lista jest pusta");
		return 1;
	}

	node* current_ptr = head_init->head;
	while (current_ptr != NULL) // zwraca false jeśli current_ptr jest Null'em. True jeśli jest inny.
	{
		node* next_ptr = current_ptr->next_Node;
		printf("Wartosc Node'a =  %d\n", current_ptr->data);
		printf("Adres kolejnego node'a = %p\n",current_ptr->next_Node);
		current_ptr = next_ptr;
	}
	return 0;
}

int main(void)
{

	list* HEAD = init();
	push(HEAD, 2);
	push(HEAD, 4);
	push(HEAD, 8);
	push(HEAD, 11);
	push(HEAD, 12);
	push(HEAD, 14);
	pop_front(HEAD); //usuwam pierwszego heada(2)


	print(HEAD);
	clear(HEAD);
	return 0;
}


//current_ptr -> next_Node   //current_ptr wskazuje element listy. wyrażenie currPtr->next zwraca wartość next obiektu.





