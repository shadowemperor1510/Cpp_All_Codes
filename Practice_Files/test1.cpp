#include<iostream>
using namespace std;

class op
{
    public:
    int summ(int n)
    {
        if(n<=1)
        return 1;
        return(n+ summ(n-1));
    }
};

int main()
{
    int n;
    cout<<"Enter a no. \n";
    cin>>n;
    op sm;
    int s=sm.summ(n);
    cout<<"Summation = "<<s<<endl;
    return 0;
}