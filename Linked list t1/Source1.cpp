#include<iostream>
#include<string>
#include"Source.cpp"

int main()
{
	List<int> l;
	l.push(87);
	cout << "The pop Value:"<<l.pop() << endl;
	return 0;
}