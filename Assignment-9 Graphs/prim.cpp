#include <iostream>
#include <climits>
using namespace std;

class Graph {
    int arr[100][100];
    int V;
public:
    Graph(int V){
        this->V = V;
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                arr[i][j] = 0;
    }

    void builder(int E){
        while(E--){
            int u,v,w;
            cout << "Enter (u,v,w): "; 
            cin >>u>>v>>w;
            if(u>=0 && v>=0 && u<V && v<V && w>0)
                arr[u][v] = arr[v][u] = w;
            else E++;
        }
    }

    void prim(int start){
        int key[100], parent[100];
        bool mst[100];
        for(int i=0;i<V;i++){
            key[i] = INT_MAX;
            mst[i] = false;
            parent[i] = -1;
        }
        key[start] = 0;
        int cost = 0;

        for(int i=0;i<V-1;i++){
            int mn = INT_MAX, u = -1;
            for(int j=0;j<V;j++)
                if(!mst[j] && key[j] < mn)
                    mn = key[u=j];
            if(u==-1) break;
            mst[u] = true;
            cost += key[u];

            for(int v=0;v<V;v++)
                if(arr[u][v] && !mst[v] && arr[u][v] < key[v]){
                    key[v] = arr[u][v];
                    parent[v] = u;
                }
        }
        cout<<cost;
    }
};

int main(){
    int V,E,start;
    cin>>V>>E>>start;
    Graph g(V);
    g.builder(E);
    g.prim(start);
}
