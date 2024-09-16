#include<iostream>
using namespace std;
class chk{
    public:
    int a,b;
    chk(int c, int d){
        a=c;
        b=d;
    }
    void display(){
        cout<<a<<" "<<b<<endl;
    }
};
int main()
{
    cout<<"Hello world"<<endl;
    chk o1(2,3);
    o1.display();
    chk o2(5,6);
    o2.display();
    o2=o1;
    o2.display();
    o1.a=10;
    o1.display();
    o2.display();
    return 1;
}