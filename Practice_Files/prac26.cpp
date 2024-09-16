#include<iostream>
using namespace std;

template <class t>
class vector
{
    public:
    t* arr;
    int size;
    vector(int m)
    {
        size=m;
        arr=new t[size];
    }

    t dp(vector v)   //  t dp(vector &v) also works!
    {
        t sum=0;
        int i;
        for(i=0;i<size;i++)
        {
            sum += this->arr[i]* v.arr[i];
        }
        return sum;
    }
};
int main()
{
    vector <int> v1(3);
    v1.arr[0]=1;
    v1.arr[1]=2;
    v1.arr[2]=3;

    vector <int> v2(3);
    v2.arr[0]=4;
    v2.arr[1]=5;
    v2.arr[2]=6;
    
    int d=v1.dp(v2);
    cout<<"Dot product= "<<d<<endl;
    return 0;
}