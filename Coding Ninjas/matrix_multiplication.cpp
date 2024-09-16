#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

int memoi(int *arr, int n, int** dp, int s, int e){
    if(e-s==1){
        return 0;
    }
    if(dp[s][e]!=0){
        return dp[s][e];
    }
    int ans=INT_MAX;
    for(int i=s+1;i<e;i++){
        int t=memoi(arr,n,dp,s,i) + memoi(arr,n,dp,i,e) + arr[s]*arr[i]*arr[e];
        ans=min(ans,t);
    }
    dp[s][e]=ans;
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }
     int ans=memoi(arr,n,dp,0,n);
     return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n+1];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}