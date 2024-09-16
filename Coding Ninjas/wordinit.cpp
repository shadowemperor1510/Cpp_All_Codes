#include<iostream>
#include<cstring>
using namespace std;
bool checksequenece(char large[] , char*small) {
    if(strlen(small)> strlen(large) ){
        return false;
    }
    int i,j,k=0,count=0;
    for(i=0;i<strlen(small);i++){
        for(j=k;j<strlen(large);j++){
            if(small[i]==large[j]){
                k=j;
                count++;
                break;
            }
        }
    }
    if(count==strlen(small)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char s1[]="dgauivgdvftycighctjhvyfdxra";
    char s2[]="var";
    cout<<checksequenece(s1,s2);
    return 0;
}