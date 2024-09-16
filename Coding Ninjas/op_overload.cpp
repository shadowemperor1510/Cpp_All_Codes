#include<iostream>
using namespace std;
class fun{
    public: int a,b;
    fun(){
        a=0,b=0;
    }
    fun(int a, int b){
        this->a=a;
        this->b=b;
    }
    void operator+(fun const f2){
        a=a+f2.a;
        b=b+f2.b;
        print();
    }
    void print(){
        cout<<a<<" "<<b<<endl;
    }
};

int main(){
    fun f1(3,5);
    f1.print();
    fun f2(8,10);
    f2.print();
    f1+f2;

    return 0;
}