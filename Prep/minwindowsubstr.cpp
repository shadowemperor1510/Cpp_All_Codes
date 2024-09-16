#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s="timetocompute";
    string t="toc";
    int n=s.length();
    unordered_map<char,int> mp;
    for(auto i:t){
        mp[i]++;
    }
    int dc=mp.size();
    int i=0,j=0,ms=INT16_MAX;
    while(j<n){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                dc--;
            }
        }
        if(dc==0){
            while(dc==0){
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        ms=min(ms,j-i+1);
                        dc++;
                    }
                }
                i++;
            }
            // while(mp.find(s[i])!=mp.end()){
            //     i++;
            // }
            // dc++;
            // mp[s[i]]++;
            // i++;
        }
        j++;
    }
    cout<<"Minimum Size = "<<ms<<endl;
    return 0;
}