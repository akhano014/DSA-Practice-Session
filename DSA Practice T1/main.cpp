#include<iostream>
#include"Stackpcpp.cpp"

using namespace std;
int main() {
	Stack<int> S1;
	S1.push(32);
	S1.push(23);
	int p1;
	S1.pop(p1);
	cout << p1 << endl;

	cout << "The peak value is: " << S1.peak();
}