#include <iostream>
#include <algorithm>
using namespace std;

class edge{
    public:
    int src;
    int dest;
    int wt;
};
int getparent(int vertex, int *parent){
    if(parent[vertex]==vertex){
        return vertex;
    }
    return getparent(parent[vertex], parent);
}

bool compare(edge e1, edge e2){
    return e1.wt < e2.wt;
}

void solve_kruskal(edge* input, int v, int e){
    
    sort(input, input+e, compare);
    int count=0;
    edge* mst=new edge[v-1];
    int* parent=new int[v];
    for(int j=0;j<v;j++){
        parent[j]=j;
    }

    int i=0;
    while(count!=v-1){
        edge current=input[i];
        int psrc=getparent(current.src, parent);
        int pdest=getparent(current.dest, parent);
        if(psrc!=pdest){
            mst[count]=current;
            count++;
            parent[psrc]=pdest;
        }
        i++;
    }

    for(int i=0;i<v-1;i++){
        if(mst[i].src < mst[i].dest){
            cout<<mst[i].src<<" "<<mst[i].dest<<" "<<mst[i].wt<<endl;
        }
        else{
            cout<<mst[i].dest<<" "<<mst[i].src<<" "<<mst[i].wt<<endl;
        }
    }
}
int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    edge* input=new edge[e];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        input[i].src=a;
        input[i].dest=b;
        input[i].wt=c;
    }

    solve_kruskal(input,v,e);
    return 0;
}