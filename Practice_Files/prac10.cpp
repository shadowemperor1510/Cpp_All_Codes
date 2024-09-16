#include<iostream>
using namespace std;

class employee
{
    private:
    int a,b;

    public:
    int c,d;
    void setdata(int a1, int b1);
    void printdata()
    {
        cout<<"a= "<<a<<endl;
        cout<<"b= "<<b<<endl;
        cout<<"c= "<<c<<endl;
        cout<<"d= "<<d<<endl;
    }

};

void employee :: setdata(int x, int y)
{
    a=x;
    b=y;
}

int main()
{
    employee ag;
    cout<<"Enter 2 nos"<<endl;
    cin>>ag.c>>ag.d;
    ag.setdata(10,2);
    ag.printdata();
    return 0;
}