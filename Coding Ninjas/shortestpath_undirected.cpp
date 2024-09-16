#include<iostream>
#include<queue>
#include<vector>
#include <unordered_map>
#include <map>
using namespace std;
/*
void print(unordered_map<int,int> &mp, int dest){
    if(mp.count(dest)==0){
        cout<<dest;
        return;
    }
    cout<<dest<<" ";
    dest=mp[dest];
    print(mp,dest);
}
*/
void bfs_print(int **graph, int v, bool *visited, int src, int dest){
    queue<int> q;
    vector<int> parent(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    parent[src]=-1;
    //unordered_map<int,int> mp;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int a=q.front();
        //cout<<a<<" ";
        q.pop();
        for(int i=0;i<v;i++){
            if(graph[a][i]==1 && !visited[i]){
                q.push(i);
                parent[i]=a;
                visited[i]=true;
            }
        }
    }
    vector<int> ans;
    if(parent[dest]==dest){
        return;
    }

    while(dest!=-1){
        ans.push_back(dest);
        dest=parent[dest];
    }
    //ans.push_back(dest);
    //reverse(ans.begin(),ans.end());
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
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
    int src,dest;
    cin>>src>>dest;
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    bfs_print(graph,v,visited,src,dest);
    return 0;
}