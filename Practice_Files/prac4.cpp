#include<iostream>
using namespace std;

struct employee
{
    int f;
};

union money
{
    int rice;
    char car;
    float pounds;
};

int main()
{
    struct employee ad;
    ad.f = 10;
    cout<<ad.f<<endl;

    union money ob;
    ob.rice=5;
    ob.car= 'd';
    cout<<ob.car<<endl;

    enum meal {breakfast, lunch, snacks, dinner};
    meal m1= snacks;
    cout<<m1<<endl;
    cout<<(m1==3)<<endl;
    
    return 0;
}