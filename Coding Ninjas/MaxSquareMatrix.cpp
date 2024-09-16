#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
	int **dp=new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i]=new int[m+1];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=0;
		}
	}
	int maximum=0;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			int r=dp[i][j+1];
			int d=dp[i+1][j];
			int diag=dp[i+1][j+1];
			if(arr[i][j]==0){
				dp[i][j]=1+min(r,min(d,diag));
				maximum=max(maximum,dp[i][j]);
			}
			else{
				dp[i][j]=0;
			}
		}
	}
	return maximum;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}