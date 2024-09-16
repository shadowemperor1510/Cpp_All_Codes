#include<iostream>
using namespace std;
int vol(int);
int vol(int,int,int);
int vol(float,int);

int main()
{
    int s,l,b,h,h1;
    float r;
    cout<<"Enter side of cube"<<endl;
    cin>>s;
    cout<<"Enter sides of cuboid"<<endl;
    cin>>l>>b>>h;
    cout<<"Enter radius and height of cylinder"<<endl;
    cin>>r;
    cin>>h1;
    cout<<"volume of cube= "<<vol(s)<<endl;
    cout<<"volume of cuboid= "<<vol(l,b,h)<<endl;
    cout<<"volume of cylinder= "<<vol(r,h1)<<endl;
}
int vol(int s)
{
    return s*s*s;
}
int vol(int l, int b, int h)
{
    return l*b*h;
}
int vol(float r, int h1)
{
    return (3.14 *r*r*h1);
}