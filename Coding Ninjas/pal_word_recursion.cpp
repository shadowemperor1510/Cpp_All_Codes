#include<iostream>
//#include<string>
//#include<cstring>
using namespace std;
bool checkPalindrome(char input[]) {
    // Write your code here
    int i,k=0;
    for(i=0;input[i]!='\0';i++){
        k++;
    }
    cout<<k<<endl;
    bool c=false;
    for(i=0;i<k/2;i++){
        if(input[i]==input[k-1-i]){
            c=true;
        }
        else{
            c=false;
            break;
        }
    }
    return c;
}
int main(){
    char ch[]="naman";
    string s="naman";
    cout<<checkPalindrome(ch)<<endl;
    return 0;
}
