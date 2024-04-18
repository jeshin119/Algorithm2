#include <iostream>
#include <algorithm>
using namespace std;
int n,d[1004];
int main(){
	cin>>n;
	d[0]=1; d[1]=2;
	for(int i=2;i<n;i++){
		d[i]=(d[i-1]+d[i-2])%10007;
	}
	// for(int i=0;i<n;i++){
	// 	cout<<d[i]<<" ";
	// }
	cout<<d[n-1]%10007;
}