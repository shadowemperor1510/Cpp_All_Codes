#include<iostream>
using namespace std;

class shop
{
    int a, b;
    public:
    void set(int c, int d)
    {
        a=c;
        b=d;
    }
    void print()
    {
        cout<<"a= "<<a<<endl;
        cout<<"b= "<<b<<endl;
    }
};

int main()
{
    shop *ptr= new shop[3];
    int i;
    for(i=0; i<3; i++)
    {
        (ptr)->set(i*2, i*3);
        (ptr)->print();
        ptr++;
        //(ptr+i)->set(2,3) also works!
    }

    return 0;
}

