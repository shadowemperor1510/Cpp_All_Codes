#include <iostream>
using namespace std;
int memoi(int *arr, int n, int *a){
	if(n<=0){
		return 0;
	}
	if(a[n]!=-1){
		return a[n];
	}
	int x=arr[0]+memoi(arr+2, n-2,a);
	int y=memoi(arr+1, n-1,a);
	a[n]= max(x,y);
	return a[n];
}
int dpsol(int *arr, int n){
	int *a=new int[n+1];
	/*
	//a[n+1]=0;
	
	a[n]=0;
	for(int i=n-1;i>=0;i--){
			a[i]=max(a[i+1],a[i+2]+arr[i]);
	}
	return a[0];
    */
   a[0]=0;
   a[1]=arr[0];
   for(int i=2;i<=n;i++){
        a[i]=max(a[i-1], arr[i]+a[i-2]);
   }
	return a[n];
}
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	if(n<=0){
		return 0;
	}

	int *a=new int[n+1];
	for(int i=0;i<=n;i++){
		a[i]=-1;
	}
	int ans1=memoi(arr, n,a);
	int ans2=dpsol(arr,n);
	return ans2;
	return ans1;
	int x=arr[0]+maxMoneyLooted(arr+2, n-2);
	int y=maxMoneyLooted(arr+1, n-1);
	return max(x,y);
}
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}