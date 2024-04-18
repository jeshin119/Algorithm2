#include <iostream>
#include <algorithm>
using namespace std;
int t;
int n[12];
int	ret[12];

void cnt(){
	ret[1]=1;
	ret[2]=2;
	ret[3]=4;
	ret[4]=ret[3]+ret[2]+ret[1];
	for(int i=5;i<=11;i++){
		ret[i] = ret[i-1]+ret[i-2]+ret[i-3];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
	}
	cnt();
	for(int i=1;i<=t;i++){
		cout<<ret[n[i]]<<"\n";
	}
}