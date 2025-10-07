#include <iostream>
using namespace std;

template <class Itemtype>
class CircularQueue {
private:
    Itemtype* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n) {
        size = n;
        front = -1;
        rear = -1;
        arr = new Itemtype[size];
    }

    bool enqueue(Itemtype value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            cout << "Queue is full!" << endl;
            return false;
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        cout << value << " inserted successfully." << endl;
        return true;
    }

    Itemtype dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        Itemtype ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return ans;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue<int> c1(size);

    int choice, value;
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            c1.enqueue(value);
            break;
        case 2:
            cout << "Removed value: " << c1.dequeue() << endl;
            break;
        case 3:
            c1.display();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
