// PROGRAM TO IMPLEMENT HASH TABLE USING QUADRATIC PROBING
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

//Insert function
void HashTable::insert(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;
    while (table[(index + i * i) % TABLE_SIZE] != -1 && i < TABLE_SIZE) {
        i++;
    }
    if (i == TABLE_SIZE) {
        cout << "HASH TABLE IS FULL!\n";
        return;
    }
    index = (index + i * i) % TABLE_SIZE;
    table[index] = key;
    cout << "VALUE INSERTED AT INDEX " << index << "\n";
}

//Search function
void HashTable::search(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;
    while (table[(index + i * i) % TABLE_SIZE] != key && table[(index + i * i) % TABLE_SIZE] != -1 && i < TABLE_SIZE) {
        i++;
    }
    if (table[(index + i * i) % TABLE_SIZE] == key) {
        cout << "ELEMENT FOUND AT INDEX " << (index + i * i) % TABLE_SIZE << "\n";
    } else {
        cout << "ELEMENT NOT FOUND\n";
    }
}


//Display function
void HashTable::display() {
    cout << "HASH TABLE CONTENTS:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1)
            cout << i << ": EMPTY\n";
        else
            cout << i << ": " << table[i] << "\n";
    }
}

