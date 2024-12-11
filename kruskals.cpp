#include <iostream>
#include <climits>
using namespace std;

#define MAX_V 100
#define INF INT_MAX

int parent[MAX_V], treeRank[MAX_V];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u != root_v) {
        if (treeRank[root_u] > treeRank[root_v]) {
            parent[root_v] = root_u;
        } else if (treeRank[root_u] < treeRank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            treeRank[root_u]++;
        }
    }
}

void kruskal(int graph[MAX_V][MAX_V], int V) {
    int edges[MAX_V * MAX_V][3];
    int edgeCount = 0;

    for (int u = 0; u < V; u++) {
        for (int v = u + 1; v < V; v++) {
            if (graph[u][v] != 0 && graph[u][v] != INF) {
                edges[edgeCount][0] = graph[u][v];
                edges[edgeCount][1] = u;
                edges[edgeCount][2] = v;
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][0] > edges[j + 1][0]) {
                for (int k = 0; k < 3; k++) {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        treeRank[i] = 0;
    }

    int mstWeight = 0;
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][1];
        int v = edges[i][2];
        int weight = edges[i][0];

        if (find(u) != find(v)) {
            cout << u << " - " << v << " : " << weight << endl;
            mstWeight += weight;
            unionSet(u, v);
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX_V][MAX_V];
    cout << "Enter the adjacency matrix (use 0 for no edge, INF for no path):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    kruskal(graph, V);

    return 0;
}
