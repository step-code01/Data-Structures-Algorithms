#include <iostream>
#include <queue>
using namespace std;

class adj_matrix {
    bool** arr;
    int vertex;
    int edges;

public:
    adj_matrix(int vertex, int edges) {
        this->vertex = vertex;
        this->edges = edges;

        arr = new bool*[vertex];
        for (int i=0; i<vertex; i++) {
            arr[i] = new bool[vertex];
            for (int j=0; j<vertex; j++)
                arr[i][j] = false;
        }
    }

    ~adj_matrix() {
        for (int i = 0; i < vertex; i++) delete[] arr[i];
        delete[] arr;
    }

    void builder() {
        for (int i = 0; i < edges; i++) {
            int u, v;
            cout << "Enter (u,v): ";
            cin >> u >> v;
            if (!(u<vertex && v<vertex && u>= 0 && v>=0)) {
                i--;
                continue;
            }
            arr[u][v] = arr[v][u] = true;
        }
    }

    void DFS_util(int node, bool visited[]) {
        visited[node] = true;
        for (int v = 0; v < vertex; v++)
            if (arr[node][v] && !visited[v])
                DFS_util(v, visited);
    }

    int countComponents() {
        bool* visited = new bool[vertex];
        for (int i=0; i<vertex; i++) visited[i] = false;
        int count = 0;

        for (int i=0; i<vertex; i++) {
            if (!visited[i]) {
                DFS_util(i, visited);
                count++;
            }
        }

        return count;
    }
};

int main() {
    int V, E;
    cout << "Enter (V,E): ";
    cin >> V >> E;
    adj_matrix g(V,E);
    g.builder();
    cout << g.countComponents();
}
