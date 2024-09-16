#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter a no."<<endl;
    cin>>n;
    int i=1;
    cout<<"Enter another no."<<endl;
    cin>>m;

    do
    {
        cout<<m*i<<endl;
        i++;
    } while (i<=n);
    
    return 0;
}