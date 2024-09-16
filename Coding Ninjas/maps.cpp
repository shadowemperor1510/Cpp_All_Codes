#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> removeDuplicat(int *a, int n){
    unordered_map<int,bool> check;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(!check[a[i]]){
            v.push_back(a[i]);
            check[a[i]]=true;
        }
        /*
        if(check.count(a[i])>0){
            continue;
        }
        check[a[i]]=true;
        v.push_back(a[i]);
        */
        //check[a[i]]=true;
    }
    return v;
}
int main(){
    unordered_map<string,int> mp;
    //insert
    pair<string,int> p("ab",3);
    mp.insert(p);
    mp["cd"]=1;
    // find/access:
    cout<<mp["ab"]<<endl;
    cout<<mp["abc"]<<endl;
    cout<<mp.at("cd")<<endl;
    int a[]={5,4,6,2,4,1,5,7,9,3,8,1,4,5,0,3,2};
    int size=sizeof(a)/sizeof(a[0]);
    vector<int> v=removeDuplicat(a,size);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}