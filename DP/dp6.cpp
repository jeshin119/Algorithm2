#include <iostream>
#include <algorithm>
using namespace std;
int n,m,i,j,a[100004],d[100004];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int z=0;z<n;z++){
		cin>>a[z];
		if (z > 0)
			d[z]=a[z]+d[z-1];
		else if (z==0)
			d[0] = a[z];
	}
	for(int ii=0;ii<m;ii++){
		cin>>i>>j;
		if (i==1){
			cout<< d[j-1]<<"\n";
			continue;
		}
		cout<<d[j-1]-d[i-2]<<"\n";
	}
}