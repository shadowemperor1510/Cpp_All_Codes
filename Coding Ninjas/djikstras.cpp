#include <iostream>
#include<climits>
using namespace std;

int getmindist(int v, int* distance,bool* visited){
    int minval=-1;
    //int vertex=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (minval==-1 || distance[minval]>distance[i])){
            minval=i;
        }
    }
    return minval;
}
void dijkstras(int **edges, int v, int e){
    bool* visited=new bool[v];
    int* distance=new int[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        //distance[i]=new int[1];
        distance[i]=INT_MAX;
    }
    distance[0]=0;

    for(int i=0;i<v;i++){

        int mindistvertex=getmindist(v,distance,visited);
        visited[mindistvertex]=true;

        for(int j=0;j<v;j++){
            if(edges[mindistvertex][j]!=0 && !visited[j]){
                int cost=distance[mindistvertex] + edges[mindistvertex][j];
                if(cost<distance[j]){
                    distance[j]=cost;
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }

    delete []distance;
    delete []visited;
}
int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b]=c;
        edges[b][a]=c;
    }

    dijkstras(edges,v,e);
}