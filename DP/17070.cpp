//파이프옮기기1
#include <iostream>
using namespace std;
#define MAX_N 16
int n,w[MAX_N][MAX_N],dp[MAX_N][MAX_N][3],ret;
int go(){

}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>w[i][j];
		}
	}
	go();
	cout<<ret;
	return 0;
}