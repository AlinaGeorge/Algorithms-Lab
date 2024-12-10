#include <iostream>
using namespace std;

#define INF 99999  

void printPath(int next[100][100], int u, int v) {
    if (next[u][v] == -1) {
        cout << "No path";
        return;
    }
    cout << u << " ";
    while (u != v) {
        u = next[u][v];
        cout << u << " ";
    }
}

void floydWarshall(int graph[100][100], int n) {
    int dist[100][100];
    int next[100][100];

    // Initialize distance and next matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
                next[i][j] = j; // Point to the next vertex in the path
            else
                next[i][j] = -1; // No path
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k]; // Update the path
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Print the shortest paths
    cout << "\nShortest paths between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Path from " << i << " to " << j << ": ";
            if (dist[i][j] == INF) {
                cout << "No path\n";
            } else {
                printPath(next, i, j);
                cout << endl;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100];
    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, n);

    return 0;
}
