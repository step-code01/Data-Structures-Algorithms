#include <iostream>
#include <climits>
using namespace std;

class adj_matrix {
    int** arr;
    int vertex;
    int edges;
public:
    adj_matrix(int vertex, int edges){
        this->vertex=vertex;
        this->edges=edges;
        arr=new int*[vertex];
        for(int i=0;i<vertex;i++){
            arr[i]=new int[vertex];
            for(int j=0;j<vertex;j++)
                arr[i][j]=0;
        }
    }
    ~adj_matrix(){
        for(int i=0;i<vertex;i++) delete[] arr[i];
        delete[] arr;
    }
    void builder(){
        for(int i=0;i<edges;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(u>=0 && v>=0 && u<vertex && v<vertex && w>0)
                arr[u][v]=arr[v][u]=w;
            else i--;
        }
    }
    int dijkstra(int start){
        int dist[100];
        bool visited[100];
        for(int i=0; i<vertex; i++){
            dist[i]=INT_MAX;
            visited[i]=false;
        }
        dist[start]=0;
        for(int i=0;i<vertex-1;i++){
            int mn=INT_MAX;
            int u=-1;
            for(int j=0; j<vertex; j++)
                if(!visited[j] && dist[j]<mn)
                    mn=dist[u=j];
            if(u==-1)break;
            visited[u]=true;
            for(int v=0; v<vertex; v++)
                if(arr[u][v] && !visited[v] && dist[u]+arr[u][v]<dist[v])
                    dist[v]=dist[u]+arr[u][v];
        }
        for(int i=0;i<vertex;i++)
            cout<<dist[i]<<" ";
        return 0;
    }
};

int main(){
    int V,E,start;
    cin >> V>> E >> start;
    adj_matrix g(V,E);
    g.builder();
    g.dijkstra(start);
}
