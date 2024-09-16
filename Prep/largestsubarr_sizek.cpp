#include<iostream>
using namespace std;

int main(){
    int arr[]={2,6,4,8,7,3,1,0,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=9;
    int sum=0,ms=0;
    int i=0,j=0;
    while(j<n){
        sum+=arr[j];
        if(sum<k){
            j++;
        }
        else if(sum==k){
            ms=max(ms,j-i+1);
            j++;
        }
        else{
            while(sum>k && i<=j){
            sum=sum-arr[i];
            i++;
            }
            j++;
        }
    }
    cout<<ms<<endl;
    return 0;
}