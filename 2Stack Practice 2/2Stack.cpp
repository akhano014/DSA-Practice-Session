#include<iostream>
#include"2Stack.h"
using namespace std;
template<class Arraytype>
Stack<Arraytype>::Stack() {
	max_size = 500;
	top1 = -1;
	top2 = max_size;
	arr = new Arraytype[max_size];
}

template<class Arraytype>
Stack<Arraytype>::Stack(int size) {
	max_size = size;
	top1 = -1;
	top2 = size;
	arr = new Arraytype[size];
}

template<class Arraytype>
Stack<Arraytype>::~Stack() {
	delete[]arr;
}

template<class Arraytype>
void Stack<Arraytype>::push1(Arraytype element) {
	if (top2-top1>1) {
		top1++;
		arr[top1] = element;
		cout << "Stack1 push element is: " << element << endl;
	}
	else {
		cout << "Stack is full" << endl;
	}
}

template<class Arraytype>
void Stack<Arraytype>::push2(Arraytype element2) {
	if (top2 - top1 > 1) {
		top2--;
		arr[top2] = element2;
		cout << "Stack2 push element is: " << element << endl;
	}
	else {
		cout << "Stack is full" << endl;
	}
}

template<class Arraytype>
void Stack<Arraytype>::pop1(Arraytype& removeitem) {
	if (top1>=0) {
		removeitem = arr[top1];
		top1--;
	}
	else {
		cout << "Stack is Empty" << endl;
	}
}

template<class Arraytype>
void Stack<Arraytype>::pop2(Arraytype& removeitem2) {
	if (top2<max_size) {
		removeitem2 = arr[top2];
		top2++;
	}
	else {
		cout << "Stack is Empty" << endl;
	}
}
