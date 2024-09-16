#include<iostream>
using namespace std;
void heapify(int a[], int n, int i){
    int l=2*i+1;
    int r=2*i+2;
    int mi=i;
    if(l<n && a[l]<a[mi]){
        mi=l;
    }
    if(r<n && a[r]<a[mi]){
        mi=r;
    }
    if(mi!=i){
        swap(a[mi],a[i]);
        heapify(a,n,mi);
    }
}
void heapsort(int a[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
void print(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int i;
    int a[]={5,8,4,3,9,5,2};
    heapsort(a,7);
    print(a,7);
    return 0;
}