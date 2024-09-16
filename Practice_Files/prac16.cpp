#include<iostream>
#include<cmath>
using namespace std;

class point
{
    int x,y;
    public:
    point(int, int);
    friend void dist(point, point);
};

point :: point(int e, int f)
{
    x=e;
    y=f;
}

void dist(point v1, point v2)
{
    double d;
    d=sqrt(pow(v1.x-v2.x, 2) + pow(v1.y - v2.y, 2));
    cout<<"Distance between points= "<<d<<endl;
}

int main()
{
    int a,b,c,d;
    cout<<"Enter 2 points in 2D plane."<<endl;
    cin>>a>>b;
    cin>>c>>d;

    point o1(a,b);
    point o2(c,d);

    dist(o1,o2);

    return 0;
}