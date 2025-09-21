#pragma once
template<class Arraytype>
class Stack {
private:
	Arraytype max_size;
	Arraytype top;
	Arraytype* arr;
public:
	Stack();
	Stack(int size);
	~Stack();
	bool isEmpty()const;
	bool isFull()const;
	void push(Arraytype element);
	void pop(Arraytype& removeitem);
	int peak();
};