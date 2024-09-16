#include<iostream>
using namespace std;

class crass
{
    int a;
    public:
    crass()
    {
        cout<<"Constructor invoked \n";
        a=5;
        cout<<a<<endl;
    }
    ~crass()
    {
        cout<<"Destructor invoked \n";
        cout<<a<<endl;
    }
};

int main()
{
    cout<<"Main function \n a crated \n";
    crass a;
    {
        cout<<" b and c created \n";
        crass b,c;
    }

    return 0;
}