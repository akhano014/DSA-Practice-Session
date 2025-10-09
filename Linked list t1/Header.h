#pragma once
#include <iostream> 
#include<conio.h> 
using namespace std;
template<class ItemType>
class List
{
protected:
	struct node {
		ItemType info;
		struct node* next;
	};
	typedef struct node* NODEPTR;
	NODEPTR listptr;

public:
	List();
	~List();
	ItemType emptyList();
	void insertafter(ItemType oldvalue, ItemType newvalue);
	void deleteItem(ItemType oldvalue);
	void push(ItemType newvalue);
	ItemType pop();
};