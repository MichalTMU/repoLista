/*
 ============================================================================
 Name        : mainlist.c
 Author      : Michal
 ============================================================================
 */
#ifndef FUNCTIONS_LIST_H_
#define FUNCTIONS_LIST_H_

// Stworzone struktury
typedef struct nodeS
	{
	int data;
	struct nodeS* next_Node;
	} nodeS;

typedef struct listS
	{
	nodeS* head;
	} listS;

// Stworzone funkcje
listS* init();
int push(listS* head_init, int dane);
int pop_front(listS* head_init, int* value);
int pop_back(listS* head_init, int* value);
int print(listS* head_init);
int clear(listS* head_init);

#endif /*FUNCTIONS_LIST_H_*/



