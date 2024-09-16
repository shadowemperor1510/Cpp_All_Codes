#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int first=n/2+1;
    for(int i=0;i<=first;i++){
        for(int j=0;j<first-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}