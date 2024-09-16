#include <bits/stdc++.h> 
using namespace std;

void dfspath(int vertex, unordered_map<int,list<int>>& adjl, vector<bool>& visited, stack<int>& s){
    visited[vertex]=true;
    for(auto nb: adjl[vertex]){
        if(!visited[nb]){
            dfspath(nb,adjl,visited,s);
        }
    }
    s.push(vertex);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adjl;
    vector<int> indegree(v,0);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjl[u].push_back(v);
        indegree[v]++;
    }
    //vector<bool> visited(v);
    /*
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    */
    /*
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfspath(i,adjl,visited,s);
        }
    }
    */
    vector<int> path;
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int f=q.front();
        path.push_back(f);
        q.pop();
        for(auto nb:adjl[f]){
            indegree[nb]--;
            if(indegree[nb]==0){
                q.push(nb);
            }
        }
    }
    /*
    while(!s.empty()){
        path.push_back(s.top());
        s.pop();
    }
    */
    //vector<int> indegree(v);
    return path;
}
int main(){
    return 0;
}