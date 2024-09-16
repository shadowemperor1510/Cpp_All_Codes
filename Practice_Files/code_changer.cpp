#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    unordered_map<int,char> mp;
    for(int i=1;i<=26;i++){
        char ch=96+i;
        mp[i]=ch;
    }
    vector<string> store;
    for(int i=0;i<n;i++){
        string str="";
        for(int j=0,k=i;k<n;j++,k++){
            string temp=s.substr(j,k);
            if(temp.length()==1){
                int ch=temp[0]-48;
                str+=mp[ch];
            }
            else if(temp.length()==2){
                int ch=(temp[0]-48)*10 + (temp[1]-48);
                str+=mp[ch];
            }
            else{
                continue;
            }
        }
    }
    return 0;
}