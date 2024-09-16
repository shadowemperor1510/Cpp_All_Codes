#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        unordered_map<int,list<pair<int,int>>> adjl;
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                vector<int> v=j;
                int a=v[0];
                int b=v[1];
                adjl[i].push_back({a,b});
            }
        }
        vector<int> distance(V,INT16_MAX);
        distance[S]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        while(!pq.empty()){
            int node=pq.top().second;
            int nodedist=pq.top().first;
            pq.pop();
            
            for(auto i:adjl[node]){
                int nb=i.first;
                int nbdist=i.second;
                if(distance[nb]>nodedist+nbdist){
                    distance[nb]=nodedist+nbdist;
                    pq.push({distance[nb],nb});
                }
            }
        }
        return distance;
    }
};

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> adj[v];
    int i=0;
    while(i++<e){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int> v1,v2;
        v1.push_back(v);
        v1.push_back(w);
        adj[u].push_back(v1);
        v2.push_back(u);
        v2.push_back(w);
        adj[v].push_back(v2);
    }
    int s;
    cin>>s;
    Solution* sol=new Solution();
    vector<int> ans=sol->dijkstra(v,adj,s);

    for(int i=0;i<v;i++){
        cout<<"Node "<<i<<" : "<<ans[i]<<endl;
    }
    return 0;
}
