#include<bits/stdc++.h>
using namespace std;
void perform(){
    int n;
    cin>>n;
    long long *a=new long long[n+1];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    a[4]=7;
    if(n<=4){
        cout<<a[n]<<endl;
        return;
    }
    for(int i=5;i<=n;i++){
        long long x=a[i-1];
        long long y=0, z=0;
        if(i>=2){
            y=a[i-2];
        }
        if(i>=3){
            z=a[i-3];
        }
        a[i]=(x+y+z)%(1000000007);
    }
    cout<<a[n]%(1000000007)<<endl;
    delete []a;
}
void perform2(){
    int n;
    cin>>n;
    long long *a=new long long[n+1];
    a[0]=0;
    a[1]=1;
    a[2]=1;
    a[3]=1;
    //a[4]=7;
    /*
    if(n<=4){
        cout<<a[n]<<endl;
        return;
    }
    */
    for(int i=4;i<=n;i++){
        long long x=a[i-1];
        long long y=0, z=0;
        if(i>=2){
            y=a[i-2];
        }
        if(i>=3){
            z=a[i-3];
        }
        a[i]=1+min(x,min(y,z));
    }
    cout<<a[n]%(1000000007)<<endl;
    delete []a;
}
int main()
{
    // take input from the user.
    int t;
    cin>>t;
    while(t--){
        perform2();
    }
    return 0;
}