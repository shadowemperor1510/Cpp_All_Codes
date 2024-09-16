#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

int main(){
    string s="abcdef";  //"aabacdeefsdbabbya";
    int k=3;
    unordered_map<char,int> mp;
    int ms=0,i=0,j=0;
    int count=0;
    while(j<s.length()){
        mp[s[j]]++;
        if(mp.size()<k){
            j++;
        }
        else if(mp.size()==k){
            ms=max(ms,j-i+1);
            count++;
            j++;
        }
        else{
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()==k){
                ms=max(ms,j-i+1);
                count++;
            }
            j++;
        }
    }
    cout<<"Max size = "<<ms<<endl;
    cout<<"Count ="<<count<<endl;
    return 0;
}