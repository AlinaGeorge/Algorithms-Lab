#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX 

void primMST(int graph[100][100], int V, int start) {
    int key[100];            
    int parent[100];       
    bool inMST[100];       

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[start] = 0;


    for (int count = 0; count < V - 1; count++) {

        int minKey = INF, u;
        for (int i = 0; i < V; i++) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        inMST[u] = true; 

        for (int v = 0; v < V; v++) {
           
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
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
        }
    }
    
    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    primMST(graph, V, start);

    return 0;
}
