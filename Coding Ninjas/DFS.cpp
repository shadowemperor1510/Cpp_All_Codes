#include<iostream>
using namespace std;
void dfs_print(int **graph, int v, bool *visited, int vertex){
    cout<<vertex<<" ";
    visited[vertex]=true;
    for(int i=0;i<v;i++){
        if(graph[vertex][i]==1 && !visited[i]){
            dfs_print(graph,v,visited,i);
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

    dfs_print(graph,v,visited,0);
    return 0;
}