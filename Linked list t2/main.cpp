#include <iostream>
#include "Source.cpp"
using namespace std;

int main()
{
    List<int> list;
    int len, value;

    cout << "Enter number of nodes: ";
    cin >> len;

    list.makeStr(len);
    list.displayStr();

    cout << "\nRemoving first element..." << endl;
    list.removeFirst();
    list.displayStr();

    cout << "\nRemoving last element..." << endl;
    list.removeLast();
    list.displayStr();

    cout << "\nEnter value to remove: ";
    cin >> value;
    list.remove(value);
    list.displayStr();

    return 0;
}
