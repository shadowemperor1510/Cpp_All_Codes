#include<iostream>
using namespace std;
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	if(n==0 || n==1){
		return n;
	}
	int *a=new int[n];
	a[0]=1;
	for(int i=1;i<n;i++){
		a[i]=1;
		for(int j=i-1;j>=0;j--){
			if(arr[i]<=arr[j]){
				continue;
			}
			int p=a[j]+1;
			if(p>a[i]){
				a[i]=p;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]>ans){
			ans=a[i];
		}
	}
	delete []a;
	return ans;
}
int main(){
    int a[]={1,5,6,4,8,1,1,10};
    cout<<longestIncreasingSubsequence(a,8)<<endl;
    return 0;
}