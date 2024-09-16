#include<iostream>
#include<queue>
using namespace std;
void ksortedarray(int a[], int n, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        a[j]=pq.top();
        pq.pop();
        pq.push(a[i]);
        j++;
    }
    while(!pq.empty()){
        a[j++]=pq.top();
        pq.pop();
    }
}
int main(){
    int a[]={5,8,6,4,7};
    ksortedarray(a,5,3);
    for (int i = 0; i < 5; i++)
    {
        /* code */
        cout<<a[i]<<" ";
    }
    
    return 0;
}