#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

int main(){
    string s="abcdeedaacffwsd";
    
    unordered_map<char,int> mp;
    int ms=0,i=0,j=0;
    
    while(j<s.length()){
        mp[s[j]]++;
        if(mp.size()==j-i+1){
            ms=max(ms,j-i+1);
            j++;
            continue;
        }
        //ms=max(ms,j-i);
        while (mp.size()<j-i+1)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        j++;
        //int a=mp.size();
        // if(mp[s[j]]==1){    // if(mp.size()==j-i+1) --> map size should be equal to window size for all uniqu charaters.
        //     ms=max(ms, a);
        // }
        // else if(mp[s[j]]>1){
        //     while(mp[s[i]]!=0){
        //         mp[s[i]]--;
        //         if(mp[s[i]]==0){
        //             mp.erase(s[i]);
        //         }
        //         i++;
        //     }
        // }
        //j++;
    }
    cout<<"Max size = "<<ms<<endl;
    return 0;
}