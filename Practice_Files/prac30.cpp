#include<iostream>
#include<list>
using namespace std;

void display(list<int> &m2, int c)
{
    list<int> :: iterator it;
    int i;
    it=m2.begin();
    //cout<<*it<<endl;
    for(auto it:m2)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

void add()
{
    int i,n,inp;
    cout<<"Enter the lenght of list: ";
    cout<<endl;
    cin>>n;
    list<int> m1(n);
    cout<<"Enter the elements: \n";
    for(i=0;i<n;i++)
    {
        cin>>inp;
        m1.push_back(inp);
    }
    display(m1,n);
}

int main()
{
    //cout<<"Bazinga";
    list<char> l2(3);
    add();
    return 0;
}
