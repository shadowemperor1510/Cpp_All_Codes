#include<iostream>
using namespace std;

class point
{
    int a,b;
    public:
    point(){}
    point(int , int );

    void display()
    {
        cout<<a<<"\t"<<b<<endl;
    }
};

point :: point(int c, int d)
{
    a=c;
    b=d;
}

int main()
{
    point p1,p2,p3;
    int a,b;
    cin>>a>>b;
    p1=point(a,b);
    p2=point(a+1,b-1);
    p3=point();

    p1.display();
    p2.display();
    p3.display();

    return 0;
}