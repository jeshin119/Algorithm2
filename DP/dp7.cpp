#include <iostream>
#include <algorithm>
using namespace std;
int n,d[1000004];
int main(){
	cin>>n;
	d[1]=0;
	d[2]=1;
	for(int i=3;i<=n;i++){
		d[i]=d[i-1];
		if (i%2==0 && i%3 !=0)
			d[i] = min(d[i/2],d[i]);
		else if (i%3==0 && i%2!=0)
			d[i] = min(d[i/3],d[i]);
		else if (i%3==0 && i%2==0)
			d[i] = min(d[i],min(d[i/3],d[i/2]));
		d[i]++;
	}
	cout<<d[n]<<"\n";
	while(n){
		cout<<n<<" ";
		if (n%2==0 && n%3!=0){
			if (d[n-1]< d[n/2])
				n=n-1;
			else
				n=n/2;
		}
		else if (n%3==0 && n%2!=0){
			if (d[n-1]< d[n/3])
				n=n-1;
			else
				n=n/3;
		}
		else if (n%3==0 && n%2==0){
			if (d[n/3]< d[n/2])
				n=n/3;
			else
				n=n/2;
		}
		else{
			n=n-1;
		}
	}
}