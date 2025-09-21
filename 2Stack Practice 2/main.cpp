#include<iostream>
#include"2Stack.cpp"

using namespace std;
int main() {
	Stack<int> S1;
	Stack<float>S2;
	S1.push1(22);
	S2.push2(44.8);

	int p1;
	S1.pop1(p1);
	float p2;
	S2.pop2(p2);
	cout << "Stack 1 pop value is: " << p1 << endl;
	cout << "Stack 2 pop vlaue is: " << p2 << endl;
}