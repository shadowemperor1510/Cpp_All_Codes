#include<iostream>
using namespace std;
int main(){

    // cout<<"Hi,";
    int arr[]={2,5,6,7,9,4,5,6,1,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    int k=5;
    int sum=0, ms=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    ms=sum;

    for(int i=k;i<n;i++){
        sum= sum + arr[i] - arr[i-k];
        ms=max(sum,ms);
    }

    int i=0,j=0;
    int s2=0,ms2=0;
    while(j<n){
        if(j-i+1 <=k){
            s2+=arr[j];
            j++;
            continue;
        }
        s2+=arr[j]-arr[i];
        i++;
        j++;
        ms2=max(ms2,s2);
    }
    cout<<"Maximum sum = "<<ms<<endl;
    cout<<"Maximin sum 2 = "<<ms2<<endl;

    return 0;
}