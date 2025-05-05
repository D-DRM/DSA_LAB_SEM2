// To implement Graph ADT with an adjacency list.

#include <iostream>
using namespace std;

#define MAX 100

struct Node {
    int vertex;
    Node* next;
};

class GraphList {
private:
    Node* adjList[MAX];
    int vertices;

public:
    GraphList(int v);
    ~GraphList();
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    void searchEdge(int u, int v);
    void display();
};

int main() {
    int v;
    cout << "Enter number of vertices (<= " << MAX << "): ";
    cin >> v;

    if (v <= 0 || v > MAX) {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    GraphList graph(v);
    int choice, u, w;

    do {
        cout << "\n--- Graph Menu (Adjacency List) ---\n";
        cout << "1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two vertices to insert edge (u v): ";
                cin >> u >> w;
                graph.insertEdge(u, w);
                break;
            case 2:
                cout << "Enter two vertices to delete edge (u v): ";
                cin >> u >> w;
                graph.deleteEdge(u, w);
                break;
            case 3:
                cout << "Enter two vertices to search edge (u v): ";
                cin >> u >> w;
                graph.searchEdge(u, w);
                break;
            case 4:
                graph.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Constructor
GraphList::GraphList(int v) {
    vertices = v;
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }
}

// Destructor
GraphList::~GraphList() {
    for (int i = 0; i < vertices; ++i) {
        Node* temp = adjList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
}

// Insert edge
void GraphList::insertEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertices!\n";
        return;
    }

    Node* newNode = new Node{v, adjList[u]};
    adjList[u] = newNode;

    newNode = new Node{u, adjList[v]};
    adjList[v] = newNode;

    cout << "Edge inserted between " << u << " and " << v << ".\n";
}

// Delete edge
void GraphList::deleteEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertices!\n";
        return;
    }

    Node *temp = adjList[u], *prev = nullptr;
    while (temp) {
        if (temp->vertex == v) {
            if (prev) prev->next = temp->next;
            else adjList[u] = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    temp = adjList[v];
    prev = nullptr;
    while (temp) {
        if (temp->vertex == u) {
            if (prev) prev->next = temp->next;
            else adjList[v] = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Edge deleted between " << u << " and " << v << ".\n";
}

// Search edge
void GraphList::searchEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertices!\n";
        return;
    }

    Node* temp = adjList[u];
    while (temp) {
        if (temp->vertex == v) {
            cout << "Edge exists between " << u << " and " << v << ".\n";
            return;
        }
        temp = temp->next;
    }

    cout << "No edge exists between " << u << " and " << v << ".\n";
}

// Display graph
void GraphList::display() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << i << ": ";
        Node* temp = adjList[i];
        while (temp) {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

