#include <iostream>
#include <algorithm>
using namespace std;
int n[304],d[304][2],t;
int main(){
	cin>>t;
	for(int i=0;i<t;i++)
		cin>>n[i];
	d[0][0] = n[0];
	d[0][1] = 0;
	d[1][0] = n[1];
	d[1][1] = n[0]+n[1];
	for(int i=2;i<t;i++){
		d[i][0] = max(d[i-2][0],d[i-2][1])+n[i];
		d[i][1] = d[i-1][0]+n[i];
	}
	cout<<max(d[t-1][0],d[t-1][1]);
}