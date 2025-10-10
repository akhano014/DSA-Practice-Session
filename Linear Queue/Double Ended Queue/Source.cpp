#include<iostream>
using namespace std;
template<class DoubleType>
class DoubleQueue {
private:
	int size;
	int front;
	int rear;
	DoubleType* array;
public:
	DoubleQueue(int n) {
		size = n;
		front = -1;
		rear = -1;
		array = new DoubleType[n];
	}

	bool isFull() {
		return ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size));
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool pushfront(DoubleType value1) {
		if (isFull()) {
			cout << "Queue is full " << endl;
			return false;
		}
		else if (front == -1) {
			front = 0;
			rear = 0;
		}
		else if (front == 0 && rear!=size-1) {
			front =size - 1;
		}
		else {
			front--;
		}
		array[front] = value1;
		return true;
	}

	DoubleType popfront() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return DoubleType();
		}
		DoubleType ans = array[front];
		array[front] = -1;

		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else if (front == size-1) {
			front = 0;
		}
		else {
			front++;
		}
		return ans;
	}

	bool pushrear(DoubleType value2) {
		if (isFull()) {
			cout << "Queue is full " << endl;
			return false;
		}
		else if (front == -1) {
			front = 0;
			rear = 0;
		}
		else if (rear == size-1 && front!=0) {
			rear=0;
		}
		else {
			rear++;
		}
		array[rear] = value2;
		return true;
	}

	DoubleType poprear() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return DoubleType();
		}
		DoubleType ans2 = array[rear];
		array[rear] = -1;

		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else if (rear == 0) {
			rear = size-1;
		}
		else {
			rear--;
		}
		return ans2;
	}

	void Display() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		cout << "Double Ended Queue Elements: ";
		for (int i = front;i <= rear;i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	int size;
	cout << "Enter the size of the queue: ";
	cin >> size;

	DoubleQueue<int> doubleq(size);

	int choice, value;
	do {
		cout << "\n--- Double Ended Queue Menu ---\n";
		cout << "1. Push Front (Insert at Front)\n";
		cout << "2. Pop Front (Remove from Front)\n";
		cout << "3. Push Rear (Insert at Rear)\n";
		cout << "4. Pop Rear (Remove from Rear)\n";
		cout << "5. Display Queue\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to insert from Front: ";
			cin >> value;
			doubleq.pushfront(value);
			break;

		case 2:
			cout << "Removed value from Front: " << doubleq.popfront() << endl;
			break;

		case 3:
			cout << "Enter value to insert from Rear: ";
			cin >> value;
			doubleq.pushrear(value); 
			break;

		case 4:
			cout << "Removed value from Rear: " << doubleq.poprear() << endl;
			break;

		case 5:
			doubleq.Display();
			break;

		case 6:
			cout << "Exiting program... Thank You" << endl;
			break;

		default:
			cout << "Invalid choice!" << endl;
		}
	} while (choice != 6);

	return 0;
}