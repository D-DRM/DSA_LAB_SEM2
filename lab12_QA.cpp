//To implement Graph ADT with an adjacency matrix

#include <iostream>
using namespace std;

#define MAX 100

class GraphMatrix {
private:
    int adj[MAX][MAX];
    int vertices;

public:
    GraphMatrix(int v);
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

    GraphMatrix graph(v);
    int choice, u, w;

    do {
        cout << "\n--- Graph Menu (Adjacency Matrix) ---\n";
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
GraphMatrix::GraphMatrix(int v) {
    vertices = v;
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            adj[i][j] = 0;
}

// Insert edge
void GraphMatrix::insertEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertices!\n";
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
    cout << "Edge inserted between " << u << " and " << v << ".\n";
}

// Delete edge
void GraphMatrix::deleteEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertices!\n";
        return;
    }
    adj[u][v] = 0;
    adj[v][u] = 0;
    cout << "Edge deleted between " << u << " and " << v << ".\n";
}

// Search edge
void GraphMatrix::searchEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertices!\n";
        return;
    }
    if (adj[u][v])
        cout << "Edge exists between " << u << " and " << v << ".\n";
    else
        cout << "No edge exists between " << u << " and " << v << ".\n";
}

// Display graph
void GraphMatrix::display() {
    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < vertices; ++i)
        cout << i << " ";
    cout << "\n";

    for (int i = 0; i < vertices; ++i) {
        cout << i << ": ";
        for (int j = 0; j < vertices; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}