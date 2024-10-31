//boj 12652 1로만들기2
//bottomup으로 구현
//초기값<->로직<->마지막값 을 생각해서 구현할것.
#include <iostream>
using namespace std;
int n,a[1000004][2];
int main(){
	cin>>n;
	a[1][0]=0;a[1][1]=0;
	a[2][0]=1;a[2][1]=1;
	a[3][0]=1;a[3][1]=1;
	for(int i=4;i<=n;i++){
		a[i][0]=a[i-1][0]+1; a[i][1]=i-1;
		if (i%2==0){
			a[i][0] = min(a[i/2][0]+1, a[i][0]);
			if (a[i][0] == a[i/2][0]+1)
				a[i][1]=i/2;
		}
		if (i%3==0){
			a[i][0] = min(a[i/3][0]+1, a[i][0]);
			if (a[i][0] == a[i/3][0]+1)
				a[i][1]=i/3;
		}
	}
	cout<<a[n][0]<<"\n";
	cout<<n<<" ";
	while(n>1){
		cout<<a[n][1]<<" ";
		n=a[n][1];
	}
}