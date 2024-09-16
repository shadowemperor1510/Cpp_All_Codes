#include<iostream>
using namespace std;
int dpsol(string s, string v){
    int m=s.size();
    int n=v.size();
    int **a=new int*[m+1];
    for(int i=0;i<=m;i++){
        a[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++){
        a[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        a[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==v[j-1]){    //s[m-i]==v[n-j]
                a[i][j]=1+a[i-1][j-1];
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    return a[m][n];
}
int main(){
    string s="abcdefghi";
    string v="ace";
    cout<<dpsol(s,v)<<endl;
    return 0;
}