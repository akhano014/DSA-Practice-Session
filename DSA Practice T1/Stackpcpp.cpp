#include<iostream>
#include"Header.h"
using namespace std;
template<class Arraytype>
Stack<Arraytype>::Stack() {
	max_size = 500;
	top = -1;
	arr = new Arraytype[max_size];
}

template<class Arraytype>
Stack<Arraytype>::Stack(int size) {
	max_size = size;
	top = -1;
	arr = new Arraytype[size];
}

template<class Arraytype>
Stack<Arraytype>::~Stack() {
	delete[]arr;
}

template<class Arraytype>
bool Stack<Arraytype>::isEmpty() const{
	return (top == -1);
}

template<class Arraytype>
bool Stack<Arraytype>::isFull() const {
	return(top == max_size - 1);
}

template<class Arraytype>
void Stack<Arraytype>::push(Arraytype element) {
	if (isFull()) {
		cout << "The stack is Full"<<endl;
		exit(1);
	}
	else {
		top++;
		arr[top]=element;
	}
}

template<class Arraytype>
void Stack<Arraytype>::pop(Arraytype& removeitem) {
	if (isEmpty()) {
		cout << "The stack is Empty" << endl;
		exit(1);
	}
	else {
		removeitem=arr[top] ;
		top--;
	}
}

template<class Arraytype>
int Stack<Arraytype>::peak() {
	if (top>=0 && top<max_size) {
		return arr[top];
	}
	else {
		cout << "The satck is Empty" << endl;
		return Arraytype();
	}
}