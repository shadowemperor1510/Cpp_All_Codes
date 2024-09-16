#include<iostream>
#include<list>
using namespace std;

int main(){
    int arr[]={12,-1,-7,8,-15,30,16,28};
    int n=8;
    int k=3;
    int i=0,j=0;
    list<int> l;
    while(j<n){
        if(arr[j]<0){
            l.push_back(arr[j]);
        }
        if(j-i+1 < k){
            j++; 
        }
        else if(j-i+1==k){
            if(l.empty()){
                cout<<0<<endl;
            }
            else{
                int num= l.front();
                cout<<num<<endl;
                if(arr[i]<0)
                    l.pop_front();
            }
            i++;
            j++;
        }
    }
    return 0;
}