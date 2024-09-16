#include<iostream>
using namespace std;

class s2;
class s1
{
    int a;
    friend void swap(s1 &, s2 &);
    public:
    void set(int c)
    {
        a=c;
    }
    
};

class s2
{
    int a;
    friend void swap(s1 &, s2 &);
    public:
    void set(int c)
    {
        a=c;
    }
    
};

void swap(s1 &e, s2 &f)
{
    int tmp;
    tmp=e.a;
    e.a=f.a;
    f.a=tmp;
    cout<<e.a<<"\t"<<f.a<<endl;
}

int main()
{
    s1 x;
    s2 y;
    x.set(35);
    y.set(49);
    
    swap(x, y);

    return 0;
}