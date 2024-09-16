#include<iostream>
#include<list>
#include<queue>
#include<set>
using namespace std;

int main(){
    int arr[]={1,8,-4,-1,0,2,6,-5,7,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    //list<int> l;
    int k=3;
    int i=0,j=0;
    //int ans=INT16_MIN;
    priority_queue<int> pq;
    set<int, greater<int>> st;
    while(j<n){
        pq.push(arr[j]);
        st.insert(arr[j]);
        if(j-i+1 == k){
            cout<<*st.begin()<<endl;
            st.erase(arr[i]);
            // if(arr[i]==pq.top()){
            //     pq.pop();
            //     st.erase
            // }
            // else{
            //     st.erase(arr[i]);
            // }
            i++;
        }
        j++;
    }

    return 0;
}