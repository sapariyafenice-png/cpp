
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:

    DynamicArray(int cap = 2) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }


    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }


    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
        cout << "Inserted: " << value << endl;
    }


    void remove(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
        cout << "Deleted element at position " << pos << endl;
    }


    void display() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, pos;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            arr.insert(value);
            break;

        case 2:
            cout << "Enter position (0-based): ";
            cin >> pos;
            arr.remove(pos);
            break;

        case 3:
            arr.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
