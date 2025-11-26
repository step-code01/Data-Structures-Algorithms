#include <iostream>
#include <climits>
using namespace std;

struct Node{ 
    int d;
    int x;
    int y; 
};
class Grid{
    int arr[100][100];
    int m, n;
public:
    Grid(int m, int n) {
        this->m = m;
        this->n = n;
        cout << "Enter elements of grid: ";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
    }

    int dijkstra() {
        int dist[100][100];
        bool visited[100][100];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                dist[i][j] = INT_MAX;
                visited[i][j] = false;
            }

        dist[0][0] = arr[0][0];
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int k=0; k < m*n; k++) {
            int mn = INT_MAX, x = -1, y = -1;
            for (int i=0; i <m; i++)
                for (int j=0; j <n; j++)
                    if (!visited[i][j] && dist[i][j] < mn) {
                        mn = dist[x = i][y = j];
                    }
            if (x == -1) break;
            visited[x][y] = true;
            if (x == m-1 && y == n-1) return dist[x][y];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny])
                    if (dist[x][y] + arr[nx][ny] < dist[nx][ny])
                        dist[nx][ny] = dist[x][y] + arr[nx][ny];
            }
        }

        return dist[m - 1][n - 1];
    }
};

int main() {
    int m, n;
    cout << "Enter size of grid:";
    cin >> m >> n;
    Grid g(m, n);
    cout << g.dijkstra();
}
