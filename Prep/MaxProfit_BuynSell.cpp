#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

void topo(unordered_map<int,list<int>>& adjl, int node, vector<int>& vis, stack<int>& s){
    vis[node]=1;
    for(auto nb:adjl[node]){
        if(!vis[nb]){
            topo(adjl,nb,vis,s);
        }
    }
    s.push(node);
}
void maxProf(int n, int m, vector<int>& val, vector<int>& A, vector<int>& B){
    unordered_map<int,list<int>> adjl, adjl2;
    for(int i=0;i<m;i++){
        adjl[A[i]].push_back(B[i]);
        adjl2[B[i]].push_back(A[i]);
    }
    vector<int> vis(n,0);
    stack<int> s;
    int mini=n;
    int start=-1;
    int max_profit=0;
    for(int i=0;i<n;i++){
        if(val[i]<mini){
            mini=val[i];
            start=i;
        }
    }
    topo(adjl,start,vis,s);
    // queue<int> q;

    while (!s.empty()){
        int node = s.top();
        s.pop();
        int min_cost=INT8_MAX;
        for(auto nb:adjl2[node]){
            min_cost=min(min_cost,val[nb]);
        }
        max_profit+=val[node] - min_cost;
    }
    cout<<"Max Profit = "<<max_profit<<endl;
    
}
int main(){
    int m,n;
    cin>>n>>m;
    cout<<"Enter value for each city:\n";
    
    cout<<"Checking if github repo is qorking or not... \n";
    cout<<"Hua kya chages dekh raha? \n";
    vector<int> val;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        val[i]=a;
    }
    cout<<"Enter the city number for roads bet 2 them: A and B cities:\n";
    vector<int> A(m,0);
    vector<int> B(m,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        A[i]=a;
        B[i]=b;
    }
    maxProf(n,m,val,A,B);
    cout<<"DOne!";
    return 1;
}