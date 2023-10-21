#include <bits/stdc++.h>
using namespace std;
int n,arr[24][24];
struct s{
	void rotate(int a[][]){
		int n=a.size();
		int m=a[0].size();
		int tmp[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				tmp[i][j]=a[n-j-1][i];
			}
		}
	}
	void go(int a[][]){
		int n=a.size();
		int m=a[0].size();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j+1<m && a[i][j]==a[i][j+1])
					a[i][j]*=2;
			}
		}

	}
	int	cal(a[][]){
		int r = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				r+=a[i][j]
			}
		}
	}
}


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int cnt=5;
	while(cnt--){
		int tmp[24][24]=a;
		int ret=0;
		go(arr);
		rotate(arr);
		ret=max(ret,s.cal(arr));
	}
	cout<<ret;
}