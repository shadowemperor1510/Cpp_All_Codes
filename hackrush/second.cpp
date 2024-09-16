#include<iostream>
using namespace std;

int main(){
    int t,n;
    cin>>t;

    int i,min,k=0;
    int score=0;

    while(t--){
        cin>>n;
        int a[n];
        score=0;
        for(i=0; i<n; i++){
            cin>>a[i];
            score+=a[i];
            if(i==0){
                min=i;
            }
            if(a[i]<0){
                k++;
            }
            if(a[i]<a[min]){
                min=i;
            }
        }
        if(k!=0){           
        
        if(min!=0 && min!=n-1){
            if(a[min-1]<=a[min+1]){
                a[min+1]=a[min+1]*(-1);
                a[min]=a[min]*(-1);
                score=score+2*a[min]-2*a[min-1];
            }
            else{
                a[min-1]=a[min-1]*(-1);
                a[min]=a[min]*(-1);
                score=score+2*a[min]-2*a[min+1];
            }
        }
        else{
            if(min==0){
                a[min+1]*=-1;
                a[min]*=-1;
                score=score+2*a[min]-2*a[min-1];
            }
            if(min==n-1){
                a[min-1]*=-1;
                a[min]*=-1;
                score=score+2*a[min]-2*a[min+1];
            }
        }
    }
    
    cout<<score<<endl;
    }
    return 0;
}