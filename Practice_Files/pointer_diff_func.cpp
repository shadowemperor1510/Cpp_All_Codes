#include<iostream>
#include<list>
using namespace std;

void chnage(int* a){
    *a = 10;
    a[3]=-2;
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
}
void c2(string& s){
    s[2]='a';
    s[5]='i';
    cout<<s<<endl;
}
int main()
{
    //cout<<"Bazinga";
    //list<int> l2(3);
    int a[]={5,4,6,2,8,9};
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    chnage(a);
    cout<<endl;
    string s2="bvhsbvsu";

    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<s2<<endl;
    c2(s2);
    cout<<s2<<endl;
    return 0;
}