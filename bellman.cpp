#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

#define INF INT_MAX // Representation of infinity

void printPath(int predecessor[], int v) {
    if (v == -1) { // Base case: no predecessor
        return;
    }
    printPath(predecessor, predecessor[v]);
    cout << v << " ";
}

bool bellmanFord(int graph[100][100], int V, int src) {
    int distance[100];    // Array to store shortest distances from the source
    int predecessor[100]; // Array to store the predecessor of each vertex

    // Initialize all distances as infinity and no predecessor
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
        predecessor[i] = -1; // No predecessor initially
    }

    distance[src] = 0; // Distance to the source is 0

    // Main loop of Bellman-Ford algorithm
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != INF && distance[u] != INF && 
                    distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                    predecessor[v] = u; // Update predecessor
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && distance[u] != INF && 
                distance[u] + graph[u][v] < distance[v]) {
                cout << "Graph contains a negative weight cycle" << endl;
                return false;
            }
        }
    }

    // Print the results
    cout << "Vertex\tDistance from Source\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (distance[i] == INF) {
            cout << "INF\t\t\tNo path\n";
        } else {
            cout << distance[i] << "\t\t\t";
            printPath(predecessor, i);
            cout << endl;
        }
    }

    return true;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100];
    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF; // Treat 0 as no edge for non-diagonal elements
            }
        }
    }

    int src;
    cout << "Enter the starting vertex: ";
    cin >> src;

    bool result = bellmanFord(graph, V, src);
    if (!result) {
        cout << "The algorithm couldn't complete due to negative weight cycles." << endl;
    }

    return 0;
}
