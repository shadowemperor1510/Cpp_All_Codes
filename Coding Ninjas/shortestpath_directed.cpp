#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;
void topodfs(int vertex, unordered_map<int, list<pair<int,int>>>& adjl, vector<bool>& visited, stack<int>& s){
    visited[vertex]=true;
    for(auto nb:adjl[vertex]){
        if(!visited[nb.first]){
            topodfs(nb.first,adjl,visited,s);
        }
    }
    s.push(vertex);
}
int main(){
    int v,e;
    cin>>v>>e;
    unordered_map<int, list<pair<int,int>>> adjl;
    for(int i=0;i<e;i++){
        int a;
        pair<int,int> p;
        cin>>a>>p.first>>p.second;
        adjl[a].push_back(p);
    }
    vector<bool> visited(v);
    vector<int> distance(v, INT16_MAX);
    stack<int> s;
    int src,dest;
    cin>>src>>dest;
    topodfs(src,adjl,visited,s);

    distance[src]=0;
    while(!s.empty()){
        int f=s.top();
        s.pop();
        if(distance[f]!=INT16_MAX){
            for(auto nb:adjl[f]){
                int cost= distance[f]+nb.second;
                if(cost<distance[nb.first]){
                    distance[nb.first]=cost;
                }
            }
        }
    }

    for(int i=0;i<distance.size();i++){
        cout<<distance[i]<<" ";
    }
    //cout<<distance[dest]<<endl;
    return 0;
}