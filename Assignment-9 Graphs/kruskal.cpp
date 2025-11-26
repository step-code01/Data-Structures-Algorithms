#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u;
    int v;
    int w;
};

class adj_matrix {
    int** arr; //bool se ab int to store weight for weighted graph
    int vertex;
    int edges;

public:
    adj_matrix(int vertex, int edges) {
        this->vertex = vertex;
        this->edges = edges;

        arr = new int*[vertex];     
        for (int i = 0; i < vertex; i++) {
            arr[i] = new int[vertex]; 
            for (int j = 0; j < vertex; j++)
                arr[i][j] = 0;
        }
    }

    ~adj_matrix() {
        for (int i = 0; i < vertex; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void builder() {
        cout << "Enter " << edges << " edges (u v weight):\n";
        for (int i = 0; i < edges; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (!(u < vertex && v < vertex && u >= 0 && v >= 0)) {
                cout << "Invalid input, try again\n";
                i--;
                continue;
            }
            arr[u][v] = w;
            arr[v][u] = w;
        }
    }

    void DFS_util(int node, bool visited[]) {
        visited[node] = true;
        for (int v = 0; v < vertex; v++) {
            if (arr[node][v] > 0 && !visited[v]) 
                DFS_util(v, visited);
        }
    }

    bool isConnected(int u, int v) {
        bool* visited = new bool[vertex];
        for (int i=0; i<vertex; i++) visited[i] = false;
        DFS_util(u, visited);
        bool res = visited[v];
        delete[] visited;
        return res;
    }
    
    void kruskal() {
        Edge e[100];
        int Ecount = 0;

        for (int i=0; i<vertex; i++)
            for (int j=i+1; j<vertex; j++)
                if (arr[i][j] > 0)
                    e[Ecount++] = {i,j,arr[i][j]};

        sort(e, e + Ecount, [](Edge a, Edge b) { return a.w < b.w; }); //weight order me krra

        for (int i = 0; i < vertex; i++)
            for (int j = 0; j < vertex; j++)
                arr[i][j] = 0;

        int cost = 0;
        int added = 0;

        for (int i=0; i<Ecount && added < vertex - 1; i++) {
            if (!isConnected(e[i].u, e[i].v)) {
                arr[e[i].u][e[i].v] = e[i].w;  
                arr[e[i].v][e[i].u] = e[i].w;
                cost += e[i].w;
                added++;
            }
        }

        cout << "\nMST cost: " << cost;
    }
};

int main() {
    int V, E;
    cout << "Enter V & E: ";
    cin >> V >> E;
    adj_matrix g(V, E);
    g.builder();
    g.kruskal();
}
