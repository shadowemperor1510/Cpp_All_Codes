#include<iostream>
using namespace std;

void perform()
{
    int i,n;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(i=0; i<n; i++)
    {
        ans=ans^a[i];
    }
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;
    int i;
    while (t>0)
    {
        perform();
        t--;
    }
    return 0;
}