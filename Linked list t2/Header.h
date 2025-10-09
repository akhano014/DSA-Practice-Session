#pragma once
#include <iostream>
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
    bool emptyList();
    void makeStr(int len);
    void displayStr();
    void removeFirst();
    void removeLast();
    void remove(ItemType k);
};
