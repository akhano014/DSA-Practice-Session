#include <iostream>
#include "Header.h"
using namespace std;

template<class ItemType>
List<ItemType>::List()
{
    listptr = NULL;
}

template<class ItemType>
List<ItemType>::~List()
{
    NODEPTR p, q;
    for (p = listptr; p != NULL; )
    {
        q = p;
        p = p->next;
        delete q;
    }
}

template<class ItemType>
bool List<ItemType>::emptyList()
{
    return (listptr == NULL);
}

template<class ItemType>
void List<ItemType>::makeStr(int len)
{
    if (len <= 0)
    {
        cout << "Invalid length!" << endl;
        return;
    }

    NODEPTR temp, tail = NULL;   
    listptr = NULL;

    cout << "Enter " << len << " elements: ";
    for (int i = 0; i < len; i++)
    {
        temp = new node;
        cin >> temp->info;
        temp->next = NULL;

        if (listptr == NULL)
        {
            listptr = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}

template<class ItemType>
void List<ItemType>::displayStr()
{
    if (emptyList())
    {
        cout << "List is empty." << endl;
        return;
    }

    NODEPTR p = listptr;
    cout << "Linked List: ";
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

template<class ItemType>
void List<ItemType>::removeFirst()
{
    if (emptyList())
        return;

    NODEPTR temp = listptr;
    listptr = listptr->next;
    delete temp;
}

template<class ItemType>
void List<ItemType>::removeLast()
{
    if (emptyList())
        return;

    if (listptr->next == NULL)
    {
        delete listptr;
        listptr = NULL;
        return;
    }

    NODEPTR p = listptr;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
}

template<class ItemType>
void List<ItemType>::remove(ItemType k)
{
    if (emptyList())
        return;

    if (listptr->info == k)
    {
        NODEPTR temp = listptr;
        listptr = listptr->next;
        delete temp;
        return;
    }

    NODEPTR p = listptr;
    while (p->next != NULL && p->next->info != k)
    {
        p = p->next;
    }

    if (p->next == NULL)
    {
        cout << "Value not found." << endl;
        return;
    }

    NODEPTR temp = p->next;
    p->next = temp->next;
    delete temp;
}


template class List<int>;
