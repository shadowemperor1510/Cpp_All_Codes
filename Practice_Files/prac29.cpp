#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &u)
{
    int i;
    for(i=0; i<u.size(); i++)
    {
       cout<<u[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int i, el, size;
    vector<int> v;
    cout<<"Enter the size \n";
    cin>>size;
    for(i=0; i<size; i++)
    {
        cout<<"Enter the element: ";
        cin>>el;
        cout<<endl;
        v.push_back(el);
    }
    display(v);

    vector<int> :: iterator j =v.begin();
    v.insert(j+1, 3, 15);
    display(v);

    v.pop_back();
    display(v);

    v.erase(j+2);
    display(v);
    return 0;
}