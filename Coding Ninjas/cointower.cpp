#include <climits>
#include <iostream>
#include <string>
using namespace std;
int find(int n,int x, int y){
	if(n==0 || n==1){
		return 1;
	}
	if(n<0){
		return INT_MAX;
	}
	int a=find(n-1, x, y);
	int b=INT_MAX,c=INT_MAX;
	if(n>=x){
		b=find(n-x,x,y);
	}
	if(n>=y){
		c=find(n-y,x,y);
	}
	return 1+min(b,min(a,c));
}
int dpsol(int n, int x, int y){
	int *a=new int[n+1];
	a[0]=1;
	a[1]=1;
	for(int i=2;i<=n;i++){
		int b=INT_MAX,c=INT_MAX;
		int x=a[i-1];
		if(i>=x){
			b=a[i-x];
		}
		if(i>=y){
			c=a[i-y];
		}
		a[i]=1+min(b,min(x,c));
	}
	return a[n];
}
string findWinner(int n, int x, int y)
{
	// Write your code here .
	int ans=dpsol(n,x,y);
	string s;
	if(ans%2==0){
		s="Whis";
	}
	else{
		s="Beerus";
	}
	return s;
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}