// PROGRAM TO IMPLEMENT HASH TABLE USING CHAINING
#include <iostream>
#include <list>
using namespace std;
#define TABLE_SIZE 10

class HashTable {
private:
    list<int> table[TABLE_SIZE];
public:
    void insert(int key);
    void search(int key);
};

//Insert
void HashTable::insert(int key) {
    int index = key % TABLE_SIZE;
    table[index].push_back(key);
    cout << "VALUE INSERTED AT INDEX " << index << "\n";
}

//Search
void HashTable::search(int key) {
    int index = key % TABLE_SIZE;
    for (int val : table[index]) {
        if (val == key) {
            cout << "ELEMENT FOUND AT INDEX " << index << "\n";
            return;
        }
    }
    cout << "ELEMENT NOT FOUND\n";
}



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
            cout << "EXITED SUCCESSFULLY :)\n";
            break;
        default:
            cout << "INVALID CHOICE!\n";
        }
    } while (choice != 4);
    return 0;
}
