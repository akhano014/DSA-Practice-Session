#pragma once
template<class Arraytype>
class Stack {
private:
	int max_size;
	int top1;
	int top2;
	Arraytype* arr;
public:
	Stack();
	Stack(int size);
	~Stack();
	/*bool isEmpty()const;
	bool isFull()const;*/
	void push1(Arraytype element);
	void pop1(Arraytype& removeitem);
	void push2(Arraytype element2);
	void pop2(Arraytype& removeitem2);
	/*int peak();*/
};

