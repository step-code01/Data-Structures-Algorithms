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
        for (int i = 0; i < vertex; i++) {
            arr[i] = new bool[vertex];
            for (int j = 0; j < vertex; j++)
                arr[i][j] = false;
        }
    }

    ~adj_matrix() {
        for (int i = 0; i < vertex; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void builder() {
        cout << "Enter " << edges << " edges (u v):\n";

        for (int i = 0; i < edges; i++) {
            int u, v;

            cout << "u: ";
            cin >> u;
            cout << "v: ";
            cin >> v;

            if (!(u < vertex && v < vertex && u >= 0 && v >= 0)) {
                cout << "Invalid input, try again\n";
                i--;
                continue;
            }

            arr[u][v] = true;
            arr[v][u] = true;
        }
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    void DFS_util(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        for (int v = 0; v < vertex; v++) {
            if (arr[node][v] && !visited[v]) {
                DFS_util(v, visited);
            }
        }
    }

    void DFS(int start) {
        if (start < 0 || start >= vertex) {
            cout << "Invalid start vertex!";
            return;
        }

        bool* visited = new bool[vertex];
        for (int i = 0; i < vertex; i++) visited[i] = false;

        cout << "\nDFS Traversal: ";
        DFS_util(start, visited);
        cout << endl;

        delete[] visited;
    }
};

int main() {
    int num_vertices, num_edges;

    cout << "Enter number of vertices: ";
    cin >> num_vertices;

    cout << "Enter number of edges: ";
    cin >> num_edges;

    adj_matrix g(num_vertices, num_edges);

    g.builder();
    g.display();

    int start;

    cout << "\nEnter DFS starting node: ";
    cin >> start;
    g.DFS(start);

    return 0;
}