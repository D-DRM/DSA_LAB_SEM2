// PROGRAM TO IMPLEMENT HASH TABLE USING LINEAR PROBING
#include <iostream>
using namespace std;

#define TABLE_SIZE 10

class HashTable {
private:
    int table[TABLE_SIZE];
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    void insert(int key);
    void search(int key);
    void display();
};

int main() {
    HashTable ht;
    int choice, value;

    do {
        cout << "MENU\n1. INSERT\n2. SEARCH\n3. DISPLAY\n4. EXIT\n";
        cout << "ENTER CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ENTER VALUE: ";
                cin >> value;
                ht.insert(value);
                break;
            case 2:
                cout << "ENTER VALUE TO SEARCH: ";
                cin >> value;
                ht.search(value);
                break;
            case 3:
                ht.display();
                break;
            case 4:
                cout << "EXITED SUCCESSFULLY :)\n";
                break;
            default:
                cout << "INVALID CHOICE!\n";
        }
    } while (choice != 4);

    return 0;
}

// FUNCTION TO INSERT ELEMENT USING LINEAR PROBING
void HashTable::insert(int key) {
    int index = key % TABLE_SIZE;
    int originalIndex = index;
    int i = 0;

    while (table[index] != -1 && i < TABLE_SIZE) {
        index = (originalIndex + ++i) % TABLE_SIZE;
    }

    if (i == TABLE_SIZE) {
        cout << "HASH TABLE IS FULL!\n";
        return;
    }

    table[index] = key;
    cout << "VALUE INSERTED AT INDEX " << index << "\n";
}

// FUNCTION TO SEARCH ELEMENT USING LINEAR PROBING
void HashTable::search(int key) {
    int index = key % TABLE_SIZE;
    int originalIndex = index;
    int i = 0;

    while (table[index] != key && table[index] != -1 && i < TABLE_SIZE) {
        index = (originalIndex + ++i) % TABLE_SIZE;
    }

    if (table[index] == key) {
        cout << "ELEMENT FOUND AT INDEX " << index << "\n";
    } else {
        cout << "ELEMENT NOT FOUND\n";
    }
}

// FUNCTION TO DISPLAY HASH TABLE
void HashTable::display() {
    cout << "HASH TABLE CONTENTS:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1)
            cout << i << ": EMPTY\n";
        else
            cout << i << ": " << table[i] << "\n";
    }
}
