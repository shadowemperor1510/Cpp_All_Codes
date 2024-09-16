#include<iostream>
using namespace std;

class emperor
{
    public:
    int a,b;
    emperor(int c)
    {
        a=c;
        b=5;
    }
    emperor(){}
};

class prince : public emperor
{
    public:
    int d=7;
    prince(int e)
    {
        a=e;
    }
    void print()
    {
        cout<<d<<endl;
    }
};

int main()
{
    emperor sg(15),stg(50);
    cout<<sg.b<<endl;
    cout<<stg.b<<endl;

    prince aug(98),ag(99);
    cout<<aug.d<<endl;
    cout<<aug.a<<endl;
    cout<<ag.d<<endl;
    cout<<ag.a<<endl;
    ag.print();
    return 0;
}