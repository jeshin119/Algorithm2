#include <iostream>
#include <algorithm>
using namespace std;
int n,a[305],d[305],m;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m+=a[i];
	}
	if (n<=1){
		cout<<m;
		return 0;
	}
	d[0]=a[0];
	d[1]=a[1];
	d[2]=a[2];
	for(int i=3;i<n;i++){
		d[i]=min(d[i-2],d[i-3])+a[i];
	}
	cout << m-min(d[n-2],d[n-3]);
}