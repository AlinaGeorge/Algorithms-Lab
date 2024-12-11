#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX

void printPath(int parent[], int vertex) {
    if (vertex == -1) {
        return;
    }
    printPath(parent, parent[vertex]);
    cout << vertex << " ";
}

void primMST(int graph[100][100], int V, int src) {
    int parent[100];
    int key[100];
    bool mstSet[100];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minKey = INF;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight \tPath from Source\n";
    for (int i = 0; i < V; i++) {
        if (i != src) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\t";
            cout << src << " ";
            printPath(parent, i);
            cout << endl;
        }
    }
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
                graph[i][j] = INF;
            }
        }
    }

    int src;
    cout << "Enter the starting vertex: ";
    cin >> src;

    primMST(graph, V, src);

    return 0;
}
