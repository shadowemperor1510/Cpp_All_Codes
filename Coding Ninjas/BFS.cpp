#include <iostream>
#include<queue>
using namespace std;
void bfs_print(int **graph, int v, bool *visited, int vertex){
    queue<int> q;
    q.push(vertex);
    visited[vertex]=true;
    while(!q.empty()){
        int a=q.front();
        cout<<a<<" ";
        q.pop();
        for(int i=0;i<v;i++){
            if(graph[a][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
void bfs_disconnected(int **graph, int v, bool *visited, int vertex){
  if (v > 0) {
    bfs_print(graph, v, visited, 0);
  }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs_print(graph,v,visited,i);
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    int **graph=new int*[v];
    for(int i=0;i<v;i++){
        graph[i]=new int[v];
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    bfs_disconnected(graph,v,visited,0);
    return 0;
}