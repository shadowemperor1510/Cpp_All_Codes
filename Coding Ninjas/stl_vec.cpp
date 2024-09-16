#include <iostream>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
int main(){
    /*
    vector<string> str;
    str.push_back("Hi");
    //cout<<str<<endl;
    //cout<<str.cbegin()<<endl;
    for(string c:str){
        cout<<c<<endl;
    }
    str.push_back("Hello");
    for(string c:str){
        cout<<c;
    }
    cout<<endl;
    cout<<str.at(1)<<endl;
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    cout<<d.at(1)<<endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        cout<<v.at(i)<<" ";
        cout<<v[i]<<" ";
    }
    cout<<"\n"<<v.at(0)<<endl;
    //sort(v.begin(),v.end());
    priority_queue<int> pq;
    priority_queue<int> pq2;
    pq.push(3);
    pq.push(6);
    pq.push(4);
    pq.push(9);
    pq.push(11);
    pq.push(15);
    pq.push(5);
    pq.push(8);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq2.push(pq.top());
        pq.pop();
    }
    cout<<pq2.top()<<endl;
    pq2.pop();
    cout<<pq2.top()<<endl;
    pq2.pop();
    pq2.pop();
    cout<<pq2.top()<<endl;
    */
   int* a=new int(); // int* a=new int; also works
   *a=5;
   cout<<*a<<endl;
   cout<<a<<endl;
    return 0;
}