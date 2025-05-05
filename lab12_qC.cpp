//To implement Graph ADT with the implementation for Prim’s algorithm, Kruskal’s algorithm, and Dijkstra’s algorithm
#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

class GraphAlgo {
private:
    int vertices;
    int graph[MAX][MAX];

public:
    GraphAlgo(int v);
    void addEdge(int u, int v, int w);
    void display();
    void prims();
    void kruskal();
    void dijkstra(int start);
};

int main() {
    int v;
    cout << "Enter number of vertices (<= " << MAX << "): ";
    cin >> v;

    if (v <= 0 || v > MAX) {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    GraphAlgo g(v);
    int choice, u, w, cost, src;

    do {
        cout << "\n--- Graph Algorithms Menu ---\n";
        cout << "1. Add Edge\n2. Display\n3. Prim’s Algorithm\n4. Kruskal’s Algorithm\n5. Dijkstra’s Algorithm\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v weight): ";
                cin >> u >> w >> cost;
                g.addEdge(u, w, cost);
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.prims();
                break;
            case 4:
                g.kruskal();
                break;
            case 5:
                cout << "Enter source vertex: ";
                cin >> src;
                g.dijkstra(src);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

// Constructor
GraphAlgo::GraphAlgo(int v) {
    vertices = v;
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            graph[i][j] = 0;
}

// Add Edge
void GraphAlgo::addEdge(int u, int v, int w) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices || w <= 0) {
        cout << "Invalid input!\n";
        return;
    }
    graph[u][v] = w;
    graph[v][u] = w;
    cout << "Edge added between " << u << " and " << v << " with weight " << w << ".\n";
}

// Display Graph
void GraphAlgo::display() {
    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < vertices; ++i)
        cout << i << " ";
    cout << "\n";

    for (int i = 0; i < vertices; ++i) {
        cout << i << ": ";
        for (int j = 0; j < vertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

// Prim's Algorithm
void GraphAlgo::prims() {
    int selected[MAX], no_edge = 0;
    int x, y;
    for (int i = 0; i < vertices; ++i)
        selected[i] = 0;

    selected[0] = 1;
    cout << "\nPrim's MST Edges:\n";

    while (no_edge < vertices - 1) {
        int min = INF;
        x = y = 0;

        for (int i = 0; i < vertices; ++i) {
            if (selected[i]) {
                for (int j = 0; j < vertices; ++j) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << "\n";
        selected[y] = 1;
        no_edge++;
    }
}

// Kruskal's Algorithm Helpers
int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[yset] = xset;
}

// Kruskal’s Algorithm
void GraphAlgo::kruskal() {
    int parent[MAX];
    int mincost = 0;
    int edge_count = 0;

    for (int i = 0; i < vertices; ++i)
        parent[i] = i;

    cout << "\nKruskal's MST Edges:\n";

    while (edge_count < vertices - 1) {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (find(parent, i) != find(parent, j) && graph[i][j]) {
                    if (graph[i][j] < min) {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            unionSet(parent, a, b);
            cout << a << " - " << b << " : " << graph[a][b] << "\n";
            mincost += graph[a][b];
            edge_count++;
        }
    }

    cout << "Total cost: " << mincost << "\n";
}

// Dijkstra’s Algorithm
void GraphAlgo::dijkstra(int start) {
    if (start < 0 || start >= vertices) {
        cout << "Invalid source vertex.\n";
        return;
    }

    int dist[MAX], visited[MAX];
    for (int i = 0; i < vertices; ++i) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int min = INF, u = -1;
        for (int i = 0; i < vertices; ++i)
            if (!visited[i] && dist[i] <= min)
                min = dist[i], u = i;

        visited[u] = 1;

        for (int v = 0; v < vertices; ++v)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < vertices; ++i)
        cout << "To " << i << ": " << dist[i] << "\n";
}