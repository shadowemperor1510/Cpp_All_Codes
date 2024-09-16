#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n,sr,sc,er,ec;
    cin>>n>>sr>>sc>>er>>ec;
    queue<pair<int,int>> q;
    vector<vector<int>> moves(n, vector<int>(n,0));
    vector<vector<bool>> visited(n, vector<bool>(n,false));
    moves[sr][sc]=0;
    visited[sr][sc]=true;
    q.push({sr,sc});
    cout<<"start"<<endl;
    int r[]={-2,-2,2,2,-1,-1,1,1};
    int c[]={-1,1,-1,1,-2,2,-2,2};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        cout<<row<<" "<<col<<endl;
        q.pop();
        if(row==er && col==ec){
            cout<<moves[row][col]<<endl;
            break;
        }
        for(int i=0;i<8;i++){
            int nr=row+r[i];
            int nc=col+c[i];
            //cout<<nr<<" "<<nc<<endl;
            if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]){
                q.push({nr,nc});
                visited[nr][nc]=true;
                moves[nr][nc]=moves[row][col]+1;
            }
        }
    }
    if(moves[er][ec]==0){
        cout<<-1<<endl;
    }
}