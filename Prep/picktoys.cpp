#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s="aabbcahhhhabbafsty";
    int l=s.length();
    int k=2;
    unordered_map<char,int> mp;
    int i=0,j=0,ms=0;
    while(j<l){
        mp[s[j]]++;
        if(mp.size()<k){
            j++;
        }
        else if(mp.size()==k){
            ms=max(ms,j-i+1);
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
            j++;
        }
    }
    cout<<"Max Toys count = "<<ms<<endl;
    return 0;
}