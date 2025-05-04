#include <iostream>
using namespace std;

class List {
private:
    int arr[5];
    int size;

public:
    List() : size(0) {}
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int pos, int value);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    int search(int value);
    void display();
    void rotate(int k);
};

int main() {
    List list;
    int choice, value, pos, k;

    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;
        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> value;
            list.insertPosition(pos, value);
            break;
        case 4:
            list.deleteBeginning();
            break;
        case 5:
            list.deleteEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deletePosition(pos);
            break;
        case 7:
            cout << "Enter value: ";
            cin >> value;
            pos = list.search(value);
            if (pos != -1)
                cout << "Found at position " << pos << endl;
            else
                cout << "Not found" << endl;
            break;
        case 8:
            list.display();
            break;
        case 9:
            cout << "Enter k: ";
            cin >> k;
            list.rotate(k);
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 10);
    
    return 0;
}

void List::insertBeginning(int value) {
    if (size == 5) {
        cout << "List is full!" << endl;
        return;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

void List::insertEnd(int value) {
    if (size == 5) {
        cout << "List is full!" << endl;
        return;
    }
    arr[size++] = value;
}

void List::insertPosition(int pos, int value) {
    if (size == 5 || pos < 1 || pos > size + 1) {
        cout << "Invalid position or list is full!" << endl;
        return;
    }
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    size++;
}

void List::deleteBeginning() {
    if (size == 0) {
        cout << "List is empty!" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void List::deleteEnd() {
    if (size == 0) {
        cout << "List is empty!" << endl;
        return;
    }
    size--;
}

void List::deletePosition(int pos) {
    if (size == 0 || pos < 1 || pos > size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int List::search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i + 1;
    }
    return -1;
}

void List::display() {
    if (size == 0) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "List: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void List::rotate(int k) {
    if (size == 0) {
        cout << "List is empty!" << endl;
        return;
    }
    k = k % size;
    if (k == 0) return;
    
    auto reverse = [&](int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    };
    
    reverse(0, size - 1);
    reverse(0, k - 1);
    reverse(k, size - 1);
}