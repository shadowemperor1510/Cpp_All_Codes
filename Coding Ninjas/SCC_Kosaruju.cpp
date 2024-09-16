#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;
void topodfs(int v, vector<int>& visited, unordered_map<int,list<int>>& adjl, stack<int>& s){
    visited[v]=1;
    for(auto nb: adjl[v]){
        if(!visited[nb]){
            topodfs(nb,visited,adjl,s);
        }
    }
    s.push(v);
}
void transdfs(int v, vector<int>& visited, unordered_map<int,list<int>>& adjl, vector<int>& s){
    visited[v]=1;
    s.push_back(v);
    for(auto nb: adjl[v]){
        if(!visited[nb]){
            transdfs(nb,visited,adjl,s);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    unordered_map<int,list<int>> adjl;
    unordered_map<int,list<int>> transpose;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjl[u].push_back(v);
        transpose[v].push_back(u);
    }
    vector<int> visited(n,0);
    stack<int> s;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            topodfs(i,visited,adjl,s);
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    vector<vector<int>> ans;
    while(!s.empty()){
        int i=s.top();
        s.pop();
        if(!visited[i]){
            vector<int> temp;
            transdfs(i,visited,transpose,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
int main(){
    return 0;
}