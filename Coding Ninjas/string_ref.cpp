#include<iostream>
using namespace std;
void change(string str){
    cout<<str<<endl;
    str="lcdfgt";
    cout<<str<<endl;
}
int main(){
    string s="abcdef";
    cout<<s<<endl;
    change(s);
    cout<<s<<endl;
    return 0;
}