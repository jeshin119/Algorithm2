#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1004][3],d[1004][3];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	d[0][0]=a[0][0]; d[0][1]=a[0][1]; d[0][2]=a[0][2];
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			if (j==0)
				d[i][j]=min(d[i-1][1],d[i-1][2]);
			else if (j==1)
				d[i][j]=min(d[i-1][0],d[i-1][2]);
			else if (j==2)
				d[i][j]=min(d[i-1][0],d[i-1][1]);
			d[i][j]+=a[i][j];
		}
	}
	cout<<min(d[n-1][0],min(d[n-1][1],d[n-1][2]));
}