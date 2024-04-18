#include <iostream>
#include <algorithm>
using namespace std;
int n,d[1000007][2];
int main(){
	cin>>n;
	d[1][0]=0;
	d[1][1]=0;
	d[2][0]=1;
	d[2][1]=1;
	for(int i=3;i<=n;i++){
		d[i][0]=d[i-1][0];
		d[i][1]=i-1;
		if (i%2==0 && i%3!=0){
			d[i][0]=min(d[i/2][0],d[i][0]);
			if (d[i][0]==d[i/2][0])
				d[i][1]=i/2;
			else
				d[i][1]=i-1;
		}
		else if (i%2!=0 &&i%3==0){
			d[i][0]=min(d[i/3][0],d[i][0]);
			if (d[i][0]==d[i/3][0])
				d[i][1]=i/3;
			else
				d[i][1]=i-1;
		}
		else if (i%2==0 && i%3==0){
			d[i][0]=min(min(d[i/3][0],d[i/2][0]),d[i][0]);
			if (d[i][0]==d[i/3][0])
				d[i][1]=i/3;
			else if (d[i][0]==d[i/2][0])
				d[i][1]=i/2;
			else if (d[i][0]==d[i-1][0])
				d[i][1]=i-1;
		}
		d[i][0]++;
	}
	cout<<d[n][0]<<"\n";
	cout<<n<<" ";
	while(n>1){
		cout<<d[n][1]<<" ";
		n=d[n][1];
	}
}