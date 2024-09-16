#include <iostream>
#include<climits>
using namespace std;

int getminvertex(int *weight, int v, bool* visited){
    int minvertex=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (minvertex==-1 || weight[i]<weight[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}
void prims(int **Graph, int v, int e){
     bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int *weight=new int[v];
    int *parent=new int[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
        parent[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;

    for(int i=0;i<v;i++){
        int minvertex=getminvertex(weight, v, visited);
        visited[minvertex]=true;

        for(int j=0;j<v;j++){
            if(Graph[minvertex][j]!=0 && !visited[j]){
                if(weight[j]>Graph[minvertex][j]){
                    weight[j]=Graph[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }

    //print
    for(int i=1;i<v;i++){
        
            if(i<parent[i]){
                cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
            }
            else{
                cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
            }
    }
}

void prim_algo(int **Graph, int v, int e, int *weight, bool *visited, int *parent, int vertex){
    if(visited[vertex]){
        return;
    }
    visited[vertex]=true;
    int minwt=INT_MAX;
    int nextvertex=-1;
    for(int i=0;i<v;i++){
        if(Graph[vertex][i]!=0 && !visited[i]){
            if(weight[i]>Graph[vertex][i]){
                weight[i]=Graph[vertex][i];
                parent[i]=vertex;

                if(weight[i]<minwt){
                    minwt=weight[i];
                    nextvertex=i;
                }
                
            }
            /*
            if(weight[i]<minwt){
                    minwt=weight[i];
                    nextvertex=i;
                }
                */
        }
    }
    
    if(nextvertex==-1){
        return;
    }
    
    prim_algo(Graph,v,e,weight,visited,parent,nextvertex);
}
void print(int* parent, int* weight, int v){
    for(int i=1;i<v;i++){
        
            if(i<parent[i]){
                cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
            }
            else{
                cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
            }
    }
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **Graph=new int*[v];
    for(int i=0;i<v;i++){
        Graph[i]=new int[v];
        for(int j=0;j<v;j++){
            Graph[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Graph[a][b]=c;
        Graph[b][a]=c;
    }
    /*
    bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int *weight=new int[v];
    int *parent=new int[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
        parent[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;

    //prim_algo(Graph,v,e,weight,visited,parent,0);
    //print(parent,weight,v);

    */
    prims(Graph,v,e);
}