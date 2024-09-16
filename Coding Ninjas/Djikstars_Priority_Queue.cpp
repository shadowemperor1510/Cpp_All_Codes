#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> djikstras(int** edge, int vertices, int edges, int source){

    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    unordered_map<int,list<pair<int,int>>> adjl;

    for(int i=0;i<edges;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        int w=edge[i][2];
        adjl[u].push_back({v,w});
        adjl[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(vertices, INT_MAX);
    dist[source]=0;
    pq.push({0,source});

    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto nb:adjl[node]){
            int nebdist=nb.second;
            int neb=nb.first;
            //int cost= dist[node] + nebdist;
            if(dist[neb]>dist[node] + nebdist){
                dist[neb]=dist[node] + nebdist;
                pq.push({dist[neb],neb});
            }
        }
    }
    return dist;
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

    vector<int> ans=djikstras(edges,v,e,0);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}